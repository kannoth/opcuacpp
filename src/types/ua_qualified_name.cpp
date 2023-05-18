#include <open62541cpp/types/ua_qualified_name.hpp>

namespace opcua {
namespace types {

void UA_QualifiedName_deleter::operator()(UA_QualifiedName* q_name) {
  if (q_name != nullptr) UA_QualifiedName_delete(q_name);
}

UaQualifiedName::UaQualifiedName()
    : c_qualified_name_(UA_QualifiedName_new()) {}

UaQualifiedName::UaQualifiedName(types::ua_uint16 namespace_index,
                                 const types::ua_string& name)
    : c_qualified_name_(UA_QualifiedName_new()) {
  *c_qualified_name_ = UA_QUALIFIEDNAME_ALLOC(namespace_index, name.c_str());
}

types::ua_uint32 UaQualifiedName::hash() const {
  return UA_QualifiedName_hash(c_qualified_name_.get());
}

UA_QualifiedName* UaQualifiedName::get_cptr() const {
  return c_qualified_name_.get();
}

ua_boolean UaQualifiedName::is_null() const {
  return UA_QualifiedName_isNull(c_qualified_name_.get());
}

bool operator==(const UaQualifiedName& lhs, const UaQualifiedName& rhs) {
  if (&lhs == &rhs) return true;

  return UA_QualifiedName_equal(lhs.get_cptr(), rhs.get_cptr());
}

bool operator!=(const UaQualifiedName& lhs, const UaQualifiedName& rhs) {
  return !(lhs == rhs);
}

}  // namespace types
}  // namespace opcua