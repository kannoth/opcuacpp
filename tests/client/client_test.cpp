#include <gtest/gtest.h>

#include <open62541cpp/net/client/client.hpp>
#include <thread>

namespace opcua::net::client::test {
class clientTest : public ::testing::Test {
 protected:
  std::unique_ptr<Client> client_;
  std::thread client_thread;

 public:
    virtual void SetUp(){
        client_ = std::make_unique<Client>();
        client_thread = std::thread{[this](){client_->connect("localhost::4840");}};
    }

    virtual void TearDown(){
        client_->abort();
        client_thread.join();
    }
};
TEST_F(clientTest, dummyTestPass) { ASSERT_TRUE(true); }
TEST_F(clientTest, dummyTestFail) { EXPECT_TRUE(false); }

};  // namespace opcua::net::client::test
