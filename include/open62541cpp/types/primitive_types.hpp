#ifndef PRIMITIVE_TYPES_HPP
#define PRIMITIVE_TYPES_HPP

//#include <open62541cpp/net/client/client.hpp>
#include <open62541/types.h>

// TODO : std::string_view adoption
// #if __cplusplus >= 201703L
// #include <string_view>
// #else  // __cplusplus >= 201703L
#include <cstdint>
#include <string>
// #endif

namespace opcua {
namespace types {

using ua_boolean = bool;
using ua_byte = uint8_t;
using ua_sbyte = int8_t;
using ua_uint16 = uint16_t;
using ua_sint16 = int16_t;
using ua_uint32 = uint32_t;
using ua_sint32 = int32_t;
using ua_uint64 = uint64_t;
using ua_sint64 = int64_t;
// TODO : Create seperate class for
// ua_string
using ua_string = std::string;
using ua_byte_string = ua_string;
using ua_guid = ua_string;

}  // namespace type
}  // namespace opcua
#endif