#include <open62541cpp/types/primitive_types.hpp>
#include <open62541cpp/types/ua_node_id.hpp>

namespace opcua {
namespace type {

void UA_NodeId_deleter::operator()(UA_NodeId* id) { 
    if (id != nullptr) UA_NodeId_clear(id); 
}


}  // namespace type
}  // namespace opcua