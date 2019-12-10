cmake_minimum_required(VERSION 3.15)
project(SlayingDemons)

set(CMAKE_CXX_STANDARD 17)

# This CMake-File links the SFML Libary files for the current Host System.
# This means the Game can only be build for a Target-System on that Target-System

add_subdirectory(lua-5.3.5)
include_directories(sol2-develop/include)
include_directories(lua-5.3.5/src)
#add_subdirectory(sol2-develop)

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
        Src/Core/main.cpp
        Src/Core/Application.cpp
        Src/Core/Application.h
        Src/UI/Button.cpp
        Src/UI/Button.h
        Src/TextGlitch.cpp
        Src/TextGlitch.h
        Src/Core/DrawableObject.cpp
        Src/Core/DrawableObject.h
        Src/UI/TextOutput.cpp
        Src/UI/TextOutput.h
        Src/UI/FormattedLine.h
        Src/UI/FormattedLine.cpp
        Src/UI/FormattedWord.h
        Src/UI/FormattedWord.cpp
        Src/UI/InputField.h
        Src/UI/InputField.cpp
        Src/Core/Manageable.h Src/Core/Drawable.h Src/UI/Panel.cpp Src/UI/Panel.h Src/IO/UserInput.cpp Src/IO/UserInput.h Src/IO/FileInput.cpp Src/IO/FileInput.h Src/World.cpp Src/World.h Src/Fighter.cpp Src/Fighter.h Src/Player.cpp Src/Player.h Src/Vocabulary.cpp Src/Vocabulary.h Src/Word.cpp Src/Word.h Src/Combat/Action.cpp Src/Combat/Action.h Src/Combat/Modifier.cpp Src/Combat/Modifier.h Src/InputTextProcessor.cpp Src/InputTextProcessor.h Src/Combat/Fight.cpp Src/Combat/Fight.h Src/Combat/Attack.cpp Src/Combat/Attack.h Src/Monster.cpp Src/Monster.h)
        ScriptEngine.cpp ScriptEngine.h Script.cpp Script.h)

# find SFML packages that where linked together in DFML_DIR
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
# link executable to SFML Libaries
target_link_libraries(SlayingDemons sfml-system sfml-window sfml-graphics sfml-network sfml-audio lua)