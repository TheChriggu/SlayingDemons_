cmake_minimum_required(VERSION 3.15)
project(SlayingDemons)

set(CMAKE_CXX_STANDARD 17)

# This CMake-File links all libraries for the current Host System.
# This means the Game can only be build for a Target-System on that Target-System
# it also sets the include directories for each library and sets the Project Target

file(GLOB_RECURSE EXEC_HEADERS Src/*.h)

file(GLOB_RECURSE EXEC_SOURCES Src/*.cpp)

# set executable-files (set Project-Target)
add_executable(${PROJECT_NAME} ${EXEC_HEADERS} ${EXEC_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE Src)
target_include_directories(${PROJECT_NAME} PRIVATE strtk)

# add all libraries as subdirectories
add_subdirectory(lua-5.3.5)
add_subdirectory(SFML-2.5.1)
add_subdirectory(sol2-develop)
add_subdirectory(boost)
add_subdirectory(strtk)

# find SFML packages in SFML_DIR which was set in SFML-2.5.1 subdirectory
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

# link executable to SFML Libaries
target_link_libraries(${PROJECT_NAME}
                      sfml-system
                      sfml-window
                      sfml-graphics
                      sfml-network
                      sfml-audio
                      lua
                      Boost::filesystem)
