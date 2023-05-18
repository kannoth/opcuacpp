#include <gtest/gtest.h>

#include <open62541cpp/types/primitive_types.hpp>
#include <open62541cpp/types/ua_qualified_name.hpp>

namespace opcua::types::test {

class OpcuaQualifedNameTest : public ::testing::Test {};

TEST_F(OpcuaQualifedNameTest, UaQualifiedNameEquality) {
  auto q_name_1 = UaQualifiedName(1, "foo");
  auto q_name_2 = UaQualifiedName(0, "foo");
  auto q_name_3 = UaQualifiedName(0, "foo-bar");
  auto q_name_4 = UaQualifiedName(0, "foo");

  EXPECT_EQ(q_name_2, q_name_4);
  EXPECT_NE(q_name_1, q_name_2);
  EXPECT_NE(q_name_1, q_name_3);
  EXPECT_NE(q_name_1, q_name_4);
  EXPECT_NE(q_name_2, q_name_3);
}

TEST_F(OpcuaQualifedNameTest, NullQualifiedName) {
  auto q_name = UaQualifiedName();
  EXPECT_TRUE(q_name.is_null());
}

}  // namespace opcua::types::test