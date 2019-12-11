//
// Created by felix on 27.11.19.
//

#include "FileInput.h"
#include <fstream>
#include <iostream>
#include <filesystem>


bool sd::FileInput::IsExisting(const char *url) {
    return std::filesystem::exists(url);
}

std::string sd::FileInput::LoadNormal(const char *url) {
    std::string content;
    std::string line;

    try {
        std::ifstream file(url);
        if (file.is_open()) {
            while (std::getline(file, line)) {
                content += line + "\n";
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

std::vector<std::vector<std::string>> sd::FileInput::LoadCSV(const char *url) {
    std::vector<std::vector<std::string>> content;
    std::string field;

    try {
        std::ifstream file(url);

        if (file.is_open()) {
            content.emplace_back(std::vector<std::string>());

            while (std::getline(file, field, ',')) {
                if (field.empty()) continue;
                if (field[0] == ASCII_NEWLINE) {
                    content.emplace_back(std::vector<std::string>());
                    continue;
                }

                content.back().emplace_back(field);
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

