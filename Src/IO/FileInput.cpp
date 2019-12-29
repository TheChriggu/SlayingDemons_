//
// Created by felix on 27.11.19.
//

#include "FileInput.h"
#include <fstream>
#include <cstring>
#include <iostream>


bool sd::FileInput::IsExisting(boost::filesystem::path url) {
    return boost::filesystem::exists(url);
}

std::shared_ptr<std::string> sd::FileInput::Load(boost::filesystem::path url) {
    std::shared_ptr<std::string> content(new std::string);
    std::string line;

    try {
        std::ifstream file(url);
        if (file.is_open()) {
            while (std::getline(file, line)) {
                (*content) += line + "\n";
            }

            file.close();
        } else {
            std::cerr << "open file " << url << " failed!" << std::endl;
        }
    } catch (std::exception ex) {
        std::cerr << "Loading File failed due to exception: " << ex.what() << std::endl;
    }

    return content;
}

std::shared_ptr<std::vector<std::vector<std::string>>> sd::FileInput::LoadCSV(boost::filesystem::path url) {

    std::shared_ptr<std::vector<std::vector<std::string>>> content(new std::vector<std::vector<std::string>>);
    std::string field;

    // return if url is file is not a .csv file
    if (strstr(url.c_str(), ".csv") == nullptr)
        return content;

    try {
        std::ifstream file(url);

        if (file.is_open()) {
            content->emplace_back(std::vector<std::string>());

            while (std::getline(file, field, ',')) {
                if (field.empty()) continue;
                if (field[0] == ASCII_NEWLINE) {
                    content->emplace_back(std::vector<std::string>());
                    continue;
                }

                content->back().emplace_back(field);
            }

            file.close();
        } else {
            std::cerr << "open CSV file " << url << " failed!" << std::endl;
        }
    } catch (std::exception ex) {
        std::cerr << "Loading CSV failed due to exception: " << ex.what() << std::endl;
    }

    return content;
}

std::shared_ptr<std::vector<boost::filesystem::path>> sd::FileInput::GetFiles(boost::filesystem::path directory) {
    std::shared_ptr<std::vector<boost::filesystem::path>> content(new std::vector<boost::filesystem::path>);

    for (auto& entry : boost::filesystem::directory_iterator(directory)) {
        content->emplace_back(entry.path());
    }

    std::cout << content->size() << std::endl;

    return content;
}

