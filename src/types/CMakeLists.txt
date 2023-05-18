set (OPCUACPP_TYPES_LIB_SUFFIX "types")
set (OPCUACPP_TYPES_LIB_NAME  "opcuacpp_${OPCUACPP_TYPES_LIB_SUFFIX}")

set (OPCUACPP_TYPES_INCLUDE_DIR "${OPCUACPP_INCLUDE_DIR}/open62541cpp/types")

add_library(${OPCUACPP_TYPES_LIB_NAME})

target_sources(${OPCUACPP_TYPES_LIB_NAME}
    PRIVATE
    ${OPCUACPP_TYPES_INCLUDE_DIR}/primitive_types.hpp
    ${OPCUACPP_TYPES_INCLUDE_DIR}/types.hpp
    ${OPCUACPP_TYPES_INCLUDE_DIR}/ua_node_id.hpp
    ${OPCUACPP_TYPES_INCLUDE_DIR}/ua_qualified_name.hpp
)

target_sources(${OPCUACPP_TYPES_LIB_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SRC_DIR}ua_node_id.cpp
    ${CMAKE_CURRENT_SRC_DIR}ua_qualified_name.cpp
)

target_include_directories(${OPCUACPP_TYPES_LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

add_library(${PROJECT_SHORTNAME}::${OPCUACPP_TYPES_LIB_SUFFIX} ALIAS ${OPCUACPP_TYPES_LIB_NAME})
target_link_libraries(${OPCUACPP_TYPES_LIB_NAME} open62541::open62541 )