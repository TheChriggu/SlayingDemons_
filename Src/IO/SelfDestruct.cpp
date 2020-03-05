//
// Created by christian.heusser on 21.02.2020.
//

#include <cstdlib>
#include "SelfDestruct.h"
#include "FileInput.h"

void sd::SelfDestruct::self_destruct() {

#ifdef _WIN32
    sd::FileInput::write_file("../selfdestruct.bat",
                              "SET someOtherProgram=SlayingDemons.exe \n"
                              "TASKKILL /IM \"%someOtherProgram%\" \n"
                              "TIMEOUT /T 1  \n"
                              "start notepad  \"ThankYou.txt\" \n"
                              "@RD /S /Q %~dp0/Resources  \n"
                              "@RD /S /Q %~dp0/cmake-build-debug \n"
                              "start /b "" cmd /c del \"%~f0\"&exit /b \n"
    );
    
    std::system("../selfdestruct.bat");
#else
    sd::FileInput::write_file("../selfdestruct.sh",
                              "#!/bin/bash \n"
                              "killall -9 SlayingDemons \n"
                              "rm -r ../* \n"
                              "touch ../ThankYou.txt"
    );
    
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
