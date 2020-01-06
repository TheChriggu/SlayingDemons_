
add_library(boost_algorithm INTERFACE)
add_library(Boost::algorithm ALIAS boost_algorithm)

target_include_directories(boost_algorithm INTERFACE include)
#target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(boost_algorithm INTERFACE Boost::algorithm)