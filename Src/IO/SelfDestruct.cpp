//
// Created by christian.heusser on 21.02.2020.
//

#include <cstdlib>
#include <Event/EventArgs.h>
#include <Event/EventSystem.h>
#include "SelfDestruct.h"
#include "FileInput.h"

void sd::SelfDestruct::self_destruct() {
    //create ThankYou.txt
    std::ofstream file("../ThankYou.txt", std::ofstream::trunc);

    if (file.is_open()) {
        std::string text = "Thank you for playing 'Slaying Demons_'\n-------Team-------\nEngineering:\nFelix Konprecht\nChristian Heusser\n \nGame Design:\nLara Serzisko\nChristian Heusser\n\nArt:\nKatharina Batzel\nNora Symmank\n\nStudents at S4G - School for Games";

        file.write(text.c_str(), text.length());

        file.close();
    }

#ifdef _WIN32
    //self destructor
    auto relative_resources = boost::filesystem::path("../Resources");
    auto absolute_resources = boost::filesystem::canonical(relative_resources).string();

    auto relative_bin = boost::filesystem::path("../bin");
    auto absolute_bin = boost::filesystem::canonical(relative_bin).string();

    std::string command = "";
    command += "SET someOtherProgram=SlayingDemons.exe\n";
    command +=  "TASKKILL /IM \"%someOtherProgram%\"\n";
    //command +=  "PAUSE\n";
    command +=  "TIMEOUT /T 2 \n";
    command += "@RD /S /Q \"";
    command += absolute_bin;
    command += "\"\n";
    command += "@RD /S /Q \"";
    command += absolute_resources;
    command += "\"\n";
    command += "start notepad \"ThankYou.txt\"\n";
    command += "start /b "" cmd /c del \"%~f0\"&exit /b \n";

    sd::FileInput::write_file("../selfdestruct.bat", command);

    //caller
    sd::FileInput::write_file("../caller.bat", "cd \"..\"\nstart cmd /C start \"\" selfdestruct.bat\nstart /b \"\" cmd /c del \"%~f0\"&exit /b \n");


    auto relative = boost::filesystem::path("../caller.bat");
    auto absolute = boost::filesystem::canonical(relative).string();

    auto defeated_args = std::make_shared<EventArgs>();
    defeated_args->type = sd::EventArgs::Type::SELF_DESTRUCT;
    EventSystem::get().trigger(defeated_args);

    system(absolute.c_str());
#else
    sd::FileInput::write_file("../selfdestruct.sh",
                              "#!/bin/bash \n"
                              "killall -9 SlayingDemons \n"
                              "touch ./ThankYou.txt"
                              "rm -r ../* \n"
    );

    auto defeated_args = std::make_shared<EventArgs>();
    defeated_args->type = sd::EventArgs::Type::SELF_DESTRUCT;
    EventSystem::get().trigger(defeated_args);

    std::system("chmod +x ../selfdestruct.sh");
    std::system("../selfdestruct.sh");
#endif
    
    
    /*On windows:
     *
     * create ThankYou.txt at path ".." (top folder of game)
     *
     * create SelfDestruct.bat at path ".." (top folder of game)
     *
     * SelfDestruct.bat content:
     *
     * SET someOtherProgram=SlayingDemons.exe   --stop the game
     * TASKKILL /IM "%someOtherProgram%"
     *
     * TIMEOUT /T 1                             --wait for the game to close
     *
     * start notepad  "ThankYou.txt"            --open ThankYou.txt with notepad
     *
     * @RD /S /Q %~dp0/Resources                --delete game folders
     * @RD /S /Q %~dp0/cmake-build-debug
     *
     * --placeholder to delete files in top level folder
     *
     * start /b "" cmd /c del "%~f0"&exit /b    --destroy bat file
     *
     * run SelfDestruct.bat
     * */
}
