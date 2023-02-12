#include <gtest/gtest.h>

#include <open62541cpp/net/server/server.hpp>
#include <thread>

namespace opcua::net::server::test {

class ServerTest : public ::testing::Test {
 protected:
  std::unique_ptr<Server> server_;
  std::thread server_thread_;

 public:
  virtual void SetUp() {
    server_ = std::make_unique<Server>(4840);
    server_thread_ = std::thread{[this]() { server_->run(); }};
  }

  virtual void TearDown() {
    server_->abort();
    server_thread_.join();
  }
};

TEST_F(ServerTest, dummyTestPass) { ASSERT_TRUE(true); }

TEST_F(ServerTest, dummyTestFail) { EXPECT_TRUE(false); }

}  // namespace opcua::net::server::test