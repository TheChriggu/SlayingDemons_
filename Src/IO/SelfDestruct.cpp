//
// Created by christian.heusser on 21.02.2020.
//

#include "SelfDestruct.h"

void SelfDestruct::self_destruct() {

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
