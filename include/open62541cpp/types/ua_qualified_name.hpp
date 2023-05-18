#ifndef UA_QUALIFIED_NAME_HPP
#define UA_QUALIFIED_NAME_HPP

#include <memory>
#include <open62541cpp/types/types.hpp>

namespace opcua {
namespace types {

struct UA_QualifiedName_deleter {
  void operator()(UA_QualifiedName* q_name);
};

class UaQualifiedName {
 private:
  std::unique_ptr<UA_QualifiedName, UA_QualifiedName_deleter> c_qualified_name_;

 public:
  UaQualifiedName();
  UaQualifiedName(types::ua_uint16 namespace_index,
                  const types::ua_string& name);

  types::ua_uint32 hash() const;

  UA_QualifiedName* get_cptr() const;

  ua_boolean is_null() const;
};

bool operator==(const UaQualifiedName& lhs, const UaQualifiedName& rhs);

bool operator!=(const UaQualifiedName& lhs, const UaQualifiedName& rhs);

}  // namespace types
}  // namespace opcua
#endif