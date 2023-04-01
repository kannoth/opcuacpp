#include <gtest/gtest.h>

#include <open62541cpp/types/primitive_types.hpp>
#include <open62541cpp/types/ua_node_id.hpp>

namespace opcua::type::test {

class OpcuaNodeIdTest : public ::testing::Test {};

TEST_F(OpcuaNodeIdTest, NodeIdNumeric) {
  auto node_id_1 = UaNodeId<ua_uint32>{1, 3};
  auto node_id_2 = UaNodeId<ua_uint32>{1, 3};
  auto node_id_3 = UaNodeId<ua_uint32>{0, 3};
  auto node_id_4 = UaNodeId<ua_uint32>{1, 4};

  EXPECT_EQ(node_id_1, node_id_2);
  EXPECT_EQ(3, node_id_1.get_id());
  EXPECT_EQ(1, node_id_1.get_namespace_index());

  EXPECT_NE(node_id_3, node_id_4);
}

TEST_F(OpcuaNodeIdTest, NodeIdString) {
  auto node_id_1 = UaNodeId<ua_string>{0, "foo"};
  auto node_id_2 = UaNodeId<ua_string>{1, "foo_bar"};

  EXPECT_EQ("foo", node_id_1.get_id());
  EXPECT_EQ(node_id_1, node_id_1);
  EXPECT_NE(node_id_1, node_id_2);
}

TEST_F(OpcuaNodeIdTest, NodeIdByteString) {
  auto node_id_1 = UaNodeId<ua_byte_string>{0, "foo"};
  auto node_id_2 = UaNodeId<ua_byte_string>{1, "foo_bar"};

  EXPECT_EQ(node_id_1, node_id_1);
  EXPECT_NE(node_id_1, node_id_2);
  EXPECT_NE(node_id_1.get_id(), node_id_2.get_id());
  EXPECT_NE(node_id_1.get_namespace_index(), node_id_2.get_namespace_index());
}

TEST_F(OpcuaNodeIdTest, NodeIdGuid) {
  auto node_id_1 = UaNodeId<ua_guid>{0, "foo"};
  auto node_id_2 = UaNodeId<ua_guid>{1, "foo_bar"};

  EXPECT_EQ(node_id_1, node_id_1);
  EXPECT_NE(node_id_1, node_id_2);
  EXPECT_NE(node_id_1.get_id(), node_id_2.get_id());
  EXPECT_NE(node_id_1.get_namespace_index(), node_id_2.get_namespace_index());
}

}  // namespace opcua::type::test