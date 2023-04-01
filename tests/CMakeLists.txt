cmake_minimum_required(VERSION 3.0...3.26)

project(test_main)

add_library(test_main test_main.cc)
target_link_libraries(test_main gtest)
add_library(tests::main ALIAS test_main)

add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(exception)
add_subdirectory(types)