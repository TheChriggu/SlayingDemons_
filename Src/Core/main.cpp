#include <memory>
#include <regex>
#include <iostream>
#include "strtk.hpp"
#include "Application.h"
#include "IO/FileInput.h"


#ifdef CMAKE_HOST_WIN32
#include <windows.h>
#define SLEEP(time) Sleep(time);
#else
#include <unistd.h>
#include <IO/SelfDestruct.h>
#define SLEEP(time) usleep(time * 1000);
#endif

void startup();
void write_data(std::vector<std::string> data);

int main() {
    //startup();
    
    /*std::string prefix{"bushe"};
    std::string input1{"t bus"};
    std::string input2{"t bushes"};
    
    std::cout << static_cast<long>(input1.rfind(prefix)) << std::endl;
    std::cout << static_cast<long>(input2.rfind(prefix)) << std::endl;*/
    
    
    
    auto app = std::make_shared<sd::Application>();
    auto result = app->setup ();
    if (!result) {
        std::cerr << "Error while setting up Application!" << std::endl;
        return EXIT_FAILURE;
    }
    /*result = app->setup_splash_screens ();
    if (!result) {
        std::cerr << "Error while setting up splash screens!" << std::endl;
        return EXIT_FAILURE;
    }

    while (app->run_splash_screens ())
    {}*/
    while (app->run ())
    {}
    
    
    /*std::string text{"Inspect northern_way   "};

    std::regex pattern_1{R"(^\s*|\s*$)"};
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

void write(std::string word)
{
    for(auto c : word)
    {
        std::cout << c;
        SLEEP(50);
    }
}

void startup()
{
    std::vector<std::string> arguments;
    std::string input;

    write("Starting");
    SLEEP(1000);
    write( ".");
    SLEEP(1000);
    write( ".");
    SLEEP(1000);
    write( ".");
    SLEEP(1000);
    write(".\n");
    SLEEP(2000);
    write("Nothing you're about to see is real.\n");
    SLEEP(500);
    write ("Please remember:\n");
    SLEEP(1000);
    write ( "This is just a GAME.\n");
    SLEEP(500);
    write ( "There's absolutely nothing sinister about this. ");
    SLEEP(500);
    std::cout << "-";
    SLEEP(500);
    std::cout << "-";
    SLEEP(500);
    std::cout << "-";
    SLEEP(2000);
    write(" ABSOLUTELY NOTHING");
    SLEEP(1000);
    std::cout << "!\n";
    SLEEP(1000);
    std::cout << ".";
    SLEEP(1000);
    std::cout << ".";
    SLEEP(1000);
    std::cout << ".\n";
    SLEEP(1500);
    write("Thank you for playing 'Slaying Demons_'.\n");
    SLEEP(1000);
    write("This software was developed to test the susceptibility of random people downloading pieces of software from the internet to obvious attacks on their computers.\n");
    SLEEP(1000);
    write("Please type 'I agree' to continue.");
    std::cout << std::endl;
    write("> ");
    SLEEP(100);
    std::cin >> input;
    write("Thank you for agreeing to our terms & conditions.\n");
    write("Before we proceed we would like to ask you to take part in our survey.\n");
    write("Please enter your name:");
    std::cout << std::endl;
    write("> ");
    SLEEP(100);
    std::cin >> input;
    write("This is not your name. Please enter your name:");
    std::cout << std::endl;
    write("> ");
    SLEEP(100);
    std::cin >> input;
    arguments.emplace_back("Name: ");
    arguments.emplace_back(input);
    write("Name saved.\n");
    write("Please enter your time of birth:");
    std::cout << std::endl;
    write("> ");
    SLEEP(100);
    std::cin >> input;
    arguments.emplace_back("Birth: ");
    arguments.emplace_back(input);
    write("Birth data saved.\n");
    write("To subscribe to our monthly paperback newsletter service, please enter your physical address:");
    std::cout << std::endl;
    write("> ");
    SLEEP(100);
    std::cin >> input;
    arguments.emplace_back("Address: ");
    arguments.emplace_back(input);
    write("Address saved.\n");
    write("Please enter your height in millimeters:\n");
    write("> ");
    SLEEP(100);
    std::cin >> input;
    arguments.emplace_back("Height: ");
    arguments.emplace_back(input);
    write("Height saved.\n");
    write("Please enter the color of your eyes:");
    std::cout << std::endl;
    write("> ");
    SLEEP(100);
    std::cin >> input;
    arguments.emplace_back("Eye Color: ");
    arguments.emplace_back(input);
    write("Eye Color saved.\n");
    write("Please enter your place of birth:");
    std::cout << std::endl;
    write("> ");
    SLEEP(100);
    std::cin >> input;
    arguments.emplace_back("Birth place: ");
    arguments.emplace_back(input);
    write("Location of birth saved.\n");
    write("Please enter your nationality:");
    std::cout << std::endl;
    write("> ");
    SLEEP(100);
    std::cin >> input;
    arguments.emplace_back("Nationality: ");
    arguments.emplace_back(input);
    write_data(arguments);
    write("Nationality saved.\n");
    write("Thank you for taking part in this survey.\n");
    write("Please remember to keep your internet connection on at all times, to facilitate a proper flow of information to our servers.\n");
    write("The game will start soon.\n");
    write("Please enjoy.\n");
    SLEEP(500);
    write("loading...[5%]\n");
    SLEEP(500);
    write("-------Slaying Demons_-------\n");
    SLEEP(500);
    write("by H0nker5\n");
    SLEEP(500);
    write("\n");
    SLEEP(500);
    write("loading...[34%]\n");
    SLEEP(500);
    write("-------Team-------\n");
    SLEEP(500);
    write("Engineering:\n");
    SLEEP(500);
    write("Felix Konprecht\n");
    SLEEP(500);
    write("Christian Heusser\n");
    SLEEP(500);
    write(" \n");
    SLEEP(500);
    write("Game Design:\n");
    SLEEP(500);
    write("Lara Serzisko\n");
    SLEEP(500);
    write("Christian Heusser\n");
    SLEEP(500);
    write(" \n");
    SLEEP(500);
    write("Art:\n");
    SLEEP(500);
    write("Katharina Batzel\n");
    SLEEP(500);
    write("Nora Symmnak\n");
    SLEEP(500);
    write(" \n");
    SLEEP(500);
    write("loading...[52%]\n");
    SLEEP(500);
    write("Starting Game Window\n");
}

void write_data(std::vector<std::string> data)
{
    std::ofstream file("../Resources/InnocentFileDoNotOpen.txt", std::ofstream::trunc);

    if (file.is_open()) {


        for (auto word : data) {
            file.write(word.c_str(), word.length());
            char c = '\n';
            file.write(&c, 1);
        }
        file.close();
    }
}

