
# Link to the cmake sub-files that link the SFML libary files to the equivalent Header-files for the corresponding Host-System
# and set include Directories
set(SFML_DIR "SFML-2.5.1/${HOST_OS}/lib/cmake/SFML" PARENT_SCOPE)
target_include_directories(${PROJECT_NAME} PUBLIC "${HOST_OS}/include")

if(CMAKE_HOST_WIN32)
    file(GLOB_RECURSE SFML_LIB_FILES ${CMAKE_CURRENT_LIST_DIR}/Windows/bin/*.dll)
endif()

if(CMAKE_HOST_UNIX)
    file(GLOB_RECURSE SFML_LIB_FILES ${CMAKE_CURRENT_LIST_DIR}/Linux/lib/*.so.2.5.1)
endif()

if(CMAKE_HOST_APPLE)
    file(GLOB_RECURSE SFML_LIB_FILES ${CMAKE_CURRENT_LIST_DIR}/Linux/lib/*.2.5.1.dylib)
endif()

install(FILES ${SFML_LIB_FILES} DESTINATION ${CMAKE_SOURCE_DIR}/Build/${HOST_OS}/${CMAKE_BUILD_TYPE}/SlayingDemons/bin)
