#ifndef UA_NODE_ID_HPP
#define UA_NODE_ID_HPP

#include <open62541cpp/types/primitive_types.hpp>

namespace opcua {
namespace type {

struct UA_NodeId_deleter {
  void operator()(UA_NodeId* id);
};

template <class T>
concept is_valid_ua_node_id =
    std::same_as<ua_string, T> || std::same_as<ua_uint32, T> ||
    std::same_as<ua_byte_string, T> || std::same_as<ua_guid, T>;

template <class IdType>
  requires is_valid_ua_node_id<IdType>
class UaNodeId {
 private:
  std::unique_ptr<UA_NodeId, UA_NodeId_deleter> c_node_;

 public:
  UaNodeId() : c_node_(UA_NodeId_new()) { *c_node_ = UA_NODEID_NULL; }

  UaNodeId(ua_uint16 ns_index, IdType id) : c_node_(UA_NodeId_new()) {
    if constexpr (std::same_as<ua_string, IdType>) {
      *c_node_ =
          UA_NODEID_STRING_ALLOC(ns_index, const_cast<char*>(id.c_str()));
    } else if constexpr (std::same_as<ua_guid, IdType>) {
      *c_node_ =
          UA_NODEID_GUID(ns_index, UA_GUID(const_cast<char*>(id.c_str())));
    } else if constexpr (std::same_as<ua_byte_string, IdType>) {
      *c_node_ =
          UA_NODEID_BYTESTRING_ALLOC(ns_index, const_cast<char*>(id.c_str()));
    } else {
      *c_node_ = UA_NODEID_NUMERIC(ns_index, id);
    }
  }

  virtual ~UaNodeId() = default;

  const IdType get_id() const {
    if constexpr (std::same_as<ua_string, IdType>) {
      return ua_string(c_node_->identifier.string);
    } else if constexpr (std::same_as<ua_guid, IdType>) {
      return ua_guid(c_node_->identifier.guid);
    } else if constexpr (std::same_as<ua_byte_string, IdType>) {
      return ua_byte_string(c_node_->identifier.byteString);
    } else {
      return c_node_->identifier.numeric;
    }
  }

  const ua_uint16 get_ns_index() const { c_node_->namespaceIndex; }

  UA_NodeId* get_cptr() const { return c_node_.get(); }
};

template <class IdType>
bool operator==(const UaNodeId<IdType>& lhs, const UaNodeId<IdType>& rhs) {
  if (&lhs == &rhs) return true;

  return UA_NodeId_equal(lhs.get_cptr(), rhs.get_cptr());
}

template <class IdType>
bool operator!=(const UaNodeId<IdType>& lhs, const UaNodeId<IdType>& rhs) {
  return !(lhs == rhs);
}

}  // namespace type
}  // namespace opcua
#endif