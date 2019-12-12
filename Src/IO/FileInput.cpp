//
// Created by felix on 27.11.19.
//

#include "FileInput.h"
#include <fstream>
#include <cstring>
#include <iostream>


bool sd::FileInput::IsExisting(std::filesystem::path url) {
    return std::filesystem::exists(url);
}

std::shared_ptr<std::string> sd::FileInput::Load(std::filesystem::path url) {
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

std::shared_ptr<std::vector<std::vector<std::string>>> sd::FileInput::LoadCSV(std::filesystem::path url) {

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

std::shared_ptr<std::vector<std::filesystem::path>> sd::FileInput::GetFiles(std::filesystem::path directory) {
    std::shared_ptr<std::vector<std::filesystem::path>> content(new std::vector<std::filesystem::path>);

    for (auto& path : directory) {
        content->emplace_back(path);
    }

    return content;
}

