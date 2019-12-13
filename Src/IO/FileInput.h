//
// Created by felix on 27.11.19.
//

#ifndef SLAYINGDEMONS_FILEINPUT_H
#define SLAYINGDEMONS_FILEINPUT_H

#define ASCII_NEWLINE 13

#include <string>
#include <vector>
#include <memory>
#include <filesystem>

namespace sd {
    class FileInput {
    public:

        static bool IsExisting(std::filesystem::path url);

        static std::shared_ptr<std::vector<std::filesystem::path>> GetFiles(std::filesystem::path directory);

        static std::shared_ptr<std::string> Load(std::filesystem::path url);
        static std::shared_ptr<std::vector<std::vector<std::string>>> LoadCSV(std::filesystem::path url);
    };
}


#endif //SLAYINGDEMONS_FILEINPUT_H
