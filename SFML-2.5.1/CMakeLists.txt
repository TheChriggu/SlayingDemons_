
# Link to the cmake sub-files that link the SFML libary files to the equivalent Header-files for the corresponding Host-System
# and set include Directories
if(CMAKE_HOST_WIN32)
    set(SFML_DIR "SFML-2.5.1/Windows/lib/cmake/SFML" PARENT_SCOPE)
    target_include_directories(${PROJECT_NAME} PUBLIC "Windows/include")

    #set option that sfml libaries get linked static
    set(SFML_STATIC_LIBRARIES true)
endif()

if(CMAKE_HOST_UNIX)
    set(SFML_DIR "SFML-2.5.1/Linux/lib/cmake/SFML" PARENT_SCOPE)
    target_include_directories(${PROJECT_NAME} PUBLIC "Linux/include")
endif()

if(CMAKE_HOST_APPLE)
    set(SFML_DIR "SFML-2.5.1/Windows/lib" PARENT_SCOPE)
    target_include_directories(${PROJECT_NAME} PUBLIC "Mac/include")
endif()


