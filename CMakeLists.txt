cmake_minimum_required(VERSION 3.15)
project(SlayingDemons)

set(CMAKE_CXX_STANDARD 17)

# This CMake-File links the SFML Libary files for the current Host System.
# This means the Game can only be build for a Target-System on that Target-System

# Link to the cmake sub-files that link the SFML libary files to the equivalent Header-files for the corresponding Host-System
# and set include Directories
if(CMAKE_HOST_WIN32)
    set(SFML_DIR "SFML-2.5.1/Windows/lib/cmake/SFML")
    include_directories("SFML-2.5.1/Windows/include")

    #set option that sfml libaries get linked static
    set(SFML_STATIC_LIBRARIES true)
endif()

if(CMAKE_HOST_UNIX)
    set(SFML_DIR "SFML-2.5.1/Linux/lib/cmake/SFML")
    include_directories("SFML-2.5.1/Linux/include")
endif()

if(CMAKE_HOST_APPLE)
    set(SFML_DIR "SFML-2.5.1/Windows/lib")
    include_directories("SFML-2.5.1/Mac/include")
endif()

# set executable-files
add_executable(SlayingDemons
        main.cpp
        Application.cpp
        Application.h
        Button.cpp
        Button.h
        TextGlitch.cpp
        TextGlitch.h
        DrawableObject.cpp
        DrawableObject.h
        TextOutput.cpp
        TextOutput.h
        FormattedLine.h
        FormattedLine.cpp
        FormattedWord.h
        FormattedWord.cpp
        InputField.h
        InputField.cpp
        Manageable.h Drawable.h Panel.cpp Panel.h UserInput.cpp UserInput.h FileInput.cpp FileInput.h World.cpp World.h FightScripts/Fighter.cpp FightScripts/Fighter.h FightScripts/Player.cpp FightScripts/Player.h FightScripts/Vocabulary.cpp FightScripts/Vocabulary.h FightScripts/Word.cpp FightScripts/Word.h FightScripts/Action.cpp FightScripts/Action.h FightScripts/Modifier.cpp FightScripts/Modifier.h InputTextProcessor.cpp InputTextProcessor.h FightScripts/Fight.cpp FightScripts/Fight.h)

# find SFML packages that where linked together in DFML_DIR
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
# link executable to SFML Libaries
target_link_libraries(SlayingDemons sfml-system sfml-window sfml-graphics sfml-network sfml-audio)