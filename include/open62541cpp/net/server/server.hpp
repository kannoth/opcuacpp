#ifndef SERVER_H
#define SERVER_H

#include <atomic>
#include <memory>
#include <open62541cpp/open62541_c_server.hpp>
#include <open62541cpp/util/console_logger.hpp>
#include <open62541cpp/util/logger.hpp>
#include <thread>

namespace opcua {
namespace net {

struct UA_ServerDeleter {
  void operator()(UA_Server* server);
};

class Server {
 private:
  int port_;
  std::unique_ptr<UA_Server, UA_ServerDeleter> server_;
  std::atomic<bool> abort_;
  util::Logger<util::ConsoleLogger> logger_;

 public:
  explicit Server(int port);
  virtual ~Server() = default;

  void run();
  void abort();
};

}  // namespace net
}  // namespace opcua

#endif  // SERVER_H