#include <gtest/gtest.h>

#include <open62541cpp/net/client/client.hpp>
#include <open62541cpp/net/server/server.hpp>
#include <thread>

namespace opcua::net::client::test {
class clientTest : public ::testing::Test {
 protected:
  std::unique_ptr<Server> server_;
  std::thread server_thread_;
  std::unique_ptr<Client> client_;

 public:
  virtual void SetUp(){
    server_ = std::make_unique<Server>(4840);
    client_ = std::make_unique<Client>();
    server_thread_ = std::thread{[this]() { server_->run(); }};
  }

  virtual void TearDown(){
    server_->abort();
    server_thread_.join();
  }
};

TEST_F(clientTest, dummyTestPass) { 
  client_->connect("localhost:4840");
  // We have to handle exceptions later 
}

}// namespace opcua::net::client::test
