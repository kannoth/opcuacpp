#ifndef UA_NODE_ID_HPP
#define UA_NODE_ID_HPP

#include <memory>
#include <open62541cpp/types/types.hpp>

namespace opcua {
namespace types {

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

  UaNodeId(ua_uint16 ns_index, IdType id);

  virtual ~UaNodeId() = default;

  const IdType get_id() const;

  ua_uint16 get_namespace_index() const;

  UA_NodeId* get_cptr() const;

  ua_boolean is_null() const;
};

}  // namespace types
}  // namespace opcua

#include "ua_node_id.ipp"
#endif