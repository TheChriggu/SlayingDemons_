//
// Created by felix on 27.11.19.
//

#include "FileInput.h"
#include <iostream>
#include <sstream>


bool sd::FileInput::is_existing(boost::filesystem::path url) {
    return boost::filesystem::exists(url);
}

std::shared_ptr<std::string> sd::FileInput::load(boost::filesystem::path url) {
    std::shared_ptr<std::string> content(new std::string);
    std::string line;

    try {
        std::ifstream file(url.string());
        if (file.is_open()) {
            while (std::getline(file, line)) {
                (*content) += line + "\n";
            }

            file.close();
        } else {
            std::cerr << "open file " << url << " failed!" << std::endl;
        }
    } catch (std::exception& ex) {
        std::cerr << "Loading File failed due to exception: " << ex.what() << std::endl;
    }

    return content;
}

std::shared_ptr<std::vector<std::vector<std::string>>> sd::FileInput::load_csv(const boost::filesystem::path& url) {

    std::shared_ptr<std::vector<std::vector<std::string>>> content(new std::vector<std::vector<std::string>>);
    std::string field;
    std::string row;

    // return if url is file is not a .csv file
   /* if (strstr(url.c_str(), ".csv") == nullptr)
        return content;
*/
    try {
        std::ifstream file(url.string());

        if (file.is_open()) {

            while(std::getline(file,row,'\n')) {

                content->emplace_back(std::vector<std::string>());
                std::stringstream cheat(row);
                while (std::getline(cheat, field, ',')) {
                    if (field.empty()) continue;
/*                    if (field[0] == ASCII_NEWLINE) {
                        content->emplace_back(std::vector<std::string>());
                        continue;
                    }
*/
                    content->back().emplace_back(field);
                }

            }

            file.close();
        } else {
            std::cerr << "open CSV file " << url << " failed!" << std::endl;
        }
    } catch (std::exception& ex) {
        std::cerr << "Loading CSV failed due to exception: " << ex.what() << std::endl;
    }

    return content;
}

std::shared_ptr<std::vector<boost::filesystem::path>> sd::FileInput::get_files(const boost::filesystem::path& directory) {
    std::shared_ptr<std::vector<boost::filesystem::path>> content(new std::vector<boost::filesystem::path>);

    for (auto& entry : boost::filesystem::directory_iterator(directory)) {
        content->emplace_back(entry.path());
    }

    std::cout << content->size() << std::endl;

    return content;
}

Sp<std::vector<std::vector<std::string>>> sd::FileInput::load_tsv(const boost::filesystem::path &url) {

    std::shared_ptr<std::vector<std::vector<std::string>>> content(new std::vector<std::vector<std::string>>);
    std::string field;
    std::string row;

    try {
        std::ifstream file(url.string());

        if (file.is_open()) {

            while(std::getline(file,row,'\n')) {

                content->emplace_back(std::vector<std::string>());
                std::stringstream cheat(row);
                while (std::getline(cheat, field, '\t')) {
                    if (field.empty()) continue;

                    content->back().emplace_back(field);
                }

            }

            file.close();
        } else {
            std::cerr << "open TSV file " << url << " failed!" << std::endl;
        }
    } catch (std::exception& ex) {
        std::cerr << "Loading TSV failed due to exception: " << ex.what() << std::endl;
    }

    return content;
}

void sd::FileInput::write_tsv(const Sp<std::vector<std::vector<std::string>>> content, const boost::filesystem::path &url)
{
    try {
        std::ofstream file(url.string(), std::ofstream::trunc);

        if (file.is_open()) {

            for(auto row : *content)
            {
                for (auto word : row)
                {
                        file.write(word.c_str(), word.length());
                        char c = '\t';
                        file.write(&c, 1);
                }
                char c = '\n';
                file.write(&c, 1);
            }

            file.close();
        } else {
            std::cerr << "open TSV file " << url << " failed!" << std::endl;
        }
    } catch (std::exception& ex) {
        std::cerr << "Writing TSV failed due to exception: " << ex.what() << std::endl;
    }
}

std::string sd::FileInput::get_current_directory()
{
    return boost::filesystem::current_path().string();
}

bool sd::FileInput::is_file_existing(std::string url)
{
    return is_existing(boost::filesystem::path(url));
}

void sd::FileInput::write_file(const boost::filesystem::path &url, const std::string &content)
{
    boost::filesystem::fstream test(url, std::ios_base::openmode::_S_out);
    test << content;
}

std::string sd::FileInput::get_path_to_player_vocab() {

    auto relative = boost::filesystem::path("../Resources/Tables/PlayerVocab.tsv");
    return boost::filesystem::canonical(relative).string();
}

std::string sd::FileInput::get_path_to_player_profile() {
    auto relative = boost::filesystem::path("../Resources/InnocentFileDoNotOpen.txt");
    return boost::filesystem::canonical(relative).string();
}

