cmake_minimum_required(VERSION 3.15)
project(SlayingDemons)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_HOST_UNIX)
    message("It worked!")
else()
    message("Shit!")
endif()

#set(SFML_DIR "C:/Users/christian.heusser/Desktop/SFML-2.5.1/lib/cmake/SFML")
#find_package(SFML COMPONENTS system window graphics network audio main REQUIRED)
add_executable(SlayingDemons main.cpp)
#target_link_libraries(untitled sfml-system sfml-window sfml-graphics sfml-network sfml-audio sfml-main)