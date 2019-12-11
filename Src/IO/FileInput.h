//
// Created by felix on 27.11.19.
//

#ifndef SLAYINGDEMONS_FILEINPUT_H
#define SLAYINGDEMONS_FILEINPUT_H

#define ASCII_NEWLINE 13

#include <string>
#include <vector>
#include <memory>

namespace sd {
    class FileInput {
    public:

        static bool IsExisting(const char* url);

        static std::shared_ptr<std::vector<std::string>> GetFiles(const char* directory);

        static std::shared_ptr<std::string> Load(const char* url);
        static std::shared_ptr<std::vector<std::vector<std::string>>> LoadCSV(const char* url);
    };
}


#endif //SLAYINGDEMONS_FILEINPUT_H
