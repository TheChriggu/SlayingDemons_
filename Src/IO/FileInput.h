//
// Created by felix on 27.11.19.
//

#ifndef SLAYINGDEMONS_FILEINPUT_H
#define SLAYINGDEMONS_FILEINPUT_H

#define ASCII_NEWLINE 13

#include <string>
#include <vector>
#include "../Core/Manageable.h"

namespace sd {
    class FileInput {
    public:

        static bool IsExisting(const char* url);

        static std::string LoadNormal(const char* url);
        static std::vector<std::vector<std::string>> LoadCSV(const char* url);
    };
}


#endif //SLAYINGDEMONS_FILEINPUT_H
