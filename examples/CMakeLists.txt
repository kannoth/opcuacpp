cmake_minimum_required(VERSION 3.9.1)
project(open62541cpp-examples)

## TODO: Adjust the CMake such that it uses the installed libs
#macro(add_example EXAMPLE_NAME EXAMPLE_SOURCE)
#    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
#    target_link_libraries(${EXAMPLE_NAME} opcuacpp_client opcuacpp_server) 
#    set_source_files_properties(${EXAMPLE_NAME} PROPERTIES LINKER_LANGUAGE CXX)
#endmacro()


#add_example(example_simple_client client_simple.hpp)

#add_example(example_simple_server server_simple.hpp)

#find_package(libopcuacpp_client)
add_executable(example_simple_client client_simple.cpp)
target_link_libraries(example_simple_client opcuacpp_client) 
set_target_properties(example_simple_client PROPERTIES LINKER_LANGUAGE CXX)


add_executable(example_simple_server server_simple.cpp)
target_link_libraries(example_simple_server opcuacpp_server) 
set_target_properties(example_simple_client PROPERTIES LINKER_LANGUAGE CXX)