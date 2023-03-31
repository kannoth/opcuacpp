cmake_minimum_required(VERSION 3.0...3.26)

project(open62541cpp VERSION 0.0.1 DESCRIPTION "An wrapper for open62541 written in modern C++")
set (PROJECT_NAME "open62541cpp")
set (PROJECT_SHORTNAME "open62541cpp")

# At the moment we give support from 11
set(CMAKE_CXX_STANDARD 20)

set(OPCUACPP_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

if(MSVC)
    add_compile_options(/W3 /WX /std:c++20)
else()
    add_compile_options(-W -Wall )#-Werror)
endif()

include_directories("${OPCUACPP_INCLUDE_DIR}")
#add_library(${PROJECT_NAME} ${OPCUACPP_INCLUDE_DIR})

#libraries
set(UA_LOGLEVEL 600)
add_subdirectory(lib/open62541)
add_subdirectory(lib/googletest)

#sources
add_subdirectory(src)

#tests
include(CTest)
add_subdirectory(tests)

#examples
add_subdirectory(examples)

