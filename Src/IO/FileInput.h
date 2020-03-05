//
// Created by felix on 27.11.19.
//

#ifndef _FILEINPUT_H_
#define _FILEINPUT_H_

#define ASCII_NEWLINE 13

#include <string>
#include <vector>
#include <memory>
#include <Core/GlobalDefinitions.h>
#include "boost/filesystem.hpp"

namespace sd {
    class FileInput {
    
        
    public:

        static bool is_existing(boost::filesystem::path url);
        static bool is_file_existing(std::string url);

        static Sp<std::vector<boost::filesystem::path>> get_files(const boost::filesystem::path& directory);

        static Sp<std::string> load(boost::filesystem::path url);
        static Sp<std::vector<std::vector<std::string>>> load_csv(const boost::filesystem::path& url);
        static Sp<std::vector<std::vector<std::string>>> load_tsv(const boost::filesystem::path& url);
        static std::string get_current_directory();
    
        static void write_tsv(const Sp<std::vector<std::vector<std::string>>> values, const boost::filesystem::path& url);
        static void write_file(const boost::filesystem::path& url, const std::string& content);
    };
}


#endif //_FILEINPUT_H_
