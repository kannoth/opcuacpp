cmake_minimum_required(VERSION 3.13)

project(test_ua_node_id)

enable_testing()

add_executable(${PROJECT_NAME})

target_sources( ${PROJECT_NAME}
    PRIVATE
    ua_node_id_test.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} open62541::open62541 open62541cpp::types gtest tests::main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})