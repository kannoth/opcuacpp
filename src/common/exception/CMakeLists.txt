set (OPCUACPP_EXCEPTION_LIB_SUFFIX "exception")
set (OPCUACPP_EXCEPTION_LIB_NAME  "opcuacpp_${OPCUACPP_EXCEPTION_LIB_SUFFIX}")

set (OPCUACPP_CLIENT_INCLUDE_DIR "${OPCUACPP_INCLUDE_DIR}/open62541cpp/common/exception")

add_library(${OPCUACPP_EXCEPTION_LIB_NAME})

target_sources(${OPCUACPP_EXCEPTION_LIB_NAME}
    PRIVATE
    ${OPCUACPP_CLIENT_INCLUDE_DIR}/exceptions_core.hpp
    ${OPCUACPP_CLIENT_INCLUDE_DIR}/exceptions_extended.hpp
)

target_sources(${OPCUACPP_EXCEPTION_LIB_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SRC_DIR}exceptions_extended.cpp
)

target_include_directories(${OPCUACPP_EXCEPTION_LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

add_library(${PROJECT_SHORTNAME}::${OPCUACPP_EXCEPTION_LIB_SUFFIX} ALIAS ${OPCUACPP_EXCEPTION_LIB_NAME})
target_link_libraries(${OPCUACPP_EXCEPTION_LIB_NAME} open62541::open62541 )