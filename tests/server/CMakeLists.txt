cmake_minimum_required(VERSION 3.0...3.12)

project(test_server)

enable_testing()

add_executable(${PROJECT_NAME})

target_sources( ${PROJECT_NAME}
    PRIVATE
    server_test.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} open62541::open62541 open62541cpp::server gtest tests::main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})