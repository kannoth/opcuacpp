#ifndef UA_NODE_ID_IPP
#define UA_NODE_ID_IPP

#include <open62541cpp/types/types.hpp>

namespace opcua {
namespace types {

template <class IdType>
  requires is_valid_ua_node_id<IdType>
UaNodeId<IdType>::UaNodeId(ua_uint16 ns_index, IdType id)
    : c_node_(UA_NodeId_new()) {
  if constexpr (std::same_as<ua_string, IdType>) {
    *c_node_ = UA_NODEID_STRING_ALLOC(ns_index, const_cast<char*>(id.c_str()));

  } else if constexpr (std::same_as<ua_guid, IdType>) {
    *c_node_ = UA_NODEID_STRING_ALLOC(ns_index, const_cast<char*>(id.c_str()));

  } else if constexpr (std::same_as<ua_byte_string, IdType>) {
    *c_node_ =
        UA_NODEID_BYTESTRING_ALLOC(ns_index, const_cast<char*>(id.c_str()));

  } else {
    *c_node_ = UA_NODEID_NUMERIC(ns_index, id);
  }
}

template <class IdType>
  requires is_valid_ua_node_id<IdType>
const IdType UaNodeId<IdType>::get_id() const {
  if constexpr (std::same_as<ua_string, IdType>) {
    return ua_string(reinterpret_cast<char*>(c_node_->identifier.string.data),
                     c_node_->identifier.string.length);

  } else if constexpr (std::same_as<ua_guid,
                                    IdType>) {  // TODO : change to UA_Guid
    return ua_string(reinterpret_cast<char*>(c_node_->identifier.string.data),
                     c_node_->identifier.string.length);

  } else if constexpr (std::same_as<ua_byte_string, IdType>) {
    return ua_byte_string(
        reinterpret_cast<char*>(c_node_->identifier.byteString.data),
        c_node_->identifier.byteString.length);

  } else {
    return this->c_node_->identifier.numeric;
  }
}

template <class IdType>
  requires is_valid_ua_node_id<IdType>
ua_uint16 UaNodeId<IdType>::get_namespace_index() const {
  return c_node_->namespaceIndex;
}

template <class IdType>
  requires is_valid_ua_node_id<IdType>
UA_NodeId* UaNodeId<IdType>::get_cptr() const {
  return c_node_.get();
}

template <class IdType>
bool operator==(const UaNodeId<IdType>& lhs, const UaNodeId<IdType>& rhs) {
  if (&lhs == &rhs) return true;

  return UA_NodeId_equal(lhs.get_cptr(), rhs.get_cptr());
}

template <class IdType>
bool operator!=(const UaNodeId<IdType>& lhs, const UaNodeId<IdType>& rhs) {
  return !(lhs == rhs);
}

}  // namespace types
}  // namespace opcua
#endif