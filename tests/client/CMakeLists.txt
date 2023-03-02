cmake_minimum_required(VERSION 3.13)

project(test_client)

enable_testing()

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
    client_test.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} open62541cpp::client open62541cpp::server gtest tests::main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})