cmake_minimum_required(VERSION 3.0...3.26)

project(open62541cpp)
set (PROJECT_NAME "open62541cpp")
set (PROJECT_SHORTNAME "open62541cpp")

# At the moment we give support from 11
set(CMAKE_CXX_STANDARD 11)

set(OPCUA_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include/open62541cpp")

if(MSVC)
    add_compile_options(/W3 /WX /std:c++11)
else()
    add_compile_options(-W -Wall )#-Werror)
endif()

include_directories("${OPCUA_INCLUDE_DIR}")

#libraries
set(UA_LOGLEVEL 600)
add_subdirectory(lib/open62541)
add_subdirectory(lib/googletest)

#sources
#add_subdirectory(src)

#tests
#add_subdirectory(test)
