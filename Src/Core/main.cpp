#include <memory>
#include <regex>
#include <iostream>
#include "strtk.hpp"
#include "Application.h"

int main() {

    auto app = std::make_shared<sd::Application>();
    auto result = app->setup ();
    if (!result) {
        std::cerr << "Error while setting up Application!" << std::endl;
        return EXIT_FAILURE;
    }
    result = app->setup_splash_screens ();
    if (!result) {
        std::cerr << "Error while setting up splash screens!" << std::endl;
        return EXIT_FAILURE;
    }
    result = app->setup_main_menu ();
    if (!result) {
        std::cerr << "Error while setting up main menu!" << std::endl;
        return EXIT_FAILURE;
    }


    while (app->run_splash_screens ())
    {}


    while (app->run_main_menu ())
    {}



    while (app->run ())
    {}
    
    std::string text{"Inspect northern_way   "};
    
    /*std::regex pattern_1{R"(^\s*|\s*$)"};
    std::regex pattern_2{R"([^\s]+\s+\b)"};
    std::regex pattern_3{R"(\b\s+[^\s]+)"};
    
    std::regex pattern_X{R"(^\s*|[^\s]+\s+\b|\s*$)"};*/
    
    /*const std::regex single_word_pattern_{R"(^[^\s]+\s+$)"};
    const std::regex two_words_pattern_{R"(^[^\s]+\s+[^\s]+\s?$)"};
    const std::regex single_word_replace_pattern_{R"(^\s*|\b\s+[^\s]+|\s*$)"};
    const std::regex two_words_replace_pattern_{R"(^\s*|[^\s]+\s+\b|\s*$)"};
    
    //std::string result_2 = std::regex_replace(text, pattern_X, "");
    
    //std::cout << "#>" << result_2 << std::endl;
    
    std::cout << "#>" << std::regex_match(text, single_word_pattern_) << std::endl;
    std::cout << "#>" << std::regex_match(text, two_words_pattern_) << std::endl;*/

    return EXIT_SUCCESS;
}

