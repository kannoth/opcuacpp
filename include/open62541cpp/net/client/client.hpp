#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <atomic>
#include <memory>
#include <open62541cpp/open62541_c_client.hpp>
#include <thread>

namespace opcua {
namespace net {

struct UA_ClientDeleter {
  void operator()(UA_Client* client);
};

class Client {
    std::atomic<bool> abort_;

 private:
  std::unique_ptr<UA_Client, UA_ClientDeleter> client_;

 public:
  explicit Client();
  virtual ~Client() = default;

  // TODO: Return run and abort status
  bool connect(std::string endpoint);
  bool abort();
};

}  // namespace net
}  // namespace opcua

#endif  // CLIENT_HPP