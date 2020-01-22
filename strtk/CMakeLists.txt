
target_compile_definitions(${PROJECT_NAME} PRIVATE strtk_no_tr1_or_boost)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
