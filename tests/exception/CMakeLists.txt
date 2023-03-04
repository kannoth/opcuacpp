cmake_minimum_required(VERSION 3.13)

project(test_exception)

enable_testing()

add_executable(${PROJECT_NAME})

target_sources( ${PROJECT_NAME}
    PRIVATE
    exception_test.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} open62541cpp::client open62541cpp::exception gtest tests::main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})