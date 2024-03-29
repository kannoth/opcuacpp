#include <iostream>
#include <open62541cpp/net/server/server.hpp>
#include <open62541cpp/net/server/server_exceptions.hpp>

namespace opcua {
namespace net {

void UA_ServerDeleter::operator()(UA_Server* server) {
  if (server != nullptr) UA_Server_delete(server);
}

Server::Server(int port)
    : port_(port),
      server_(UA_Server_new()),
      abort_(false),
      logger_("Server", util::LogSeverity::trace) {
  UA_StatusCode status = UA_ServerConfig_setMinimal(
      UA_Server_getConfig(server_.get()), port, nullptr);

  UA_Server_getConfig(server_.get())->verifyRequestTimestamp =
      UA_RULEHANDLING_ACCEPT;
  logger_.log_debug("Initialized");
}

void Server::run() {
  UA_StatusCode status = UA_Server_run_startup(server_.get());

  if (UA_STATUSCODE_GOOD != status) { /* throw exception */
    logger_.log_error(opcua::diag::get_status_description_string(status));
  } else {
    logger_.log_info("Listening to port : ", port_);
  }

  while (!abort_.load()) {
    UA_UInt16 timeout = UA_Server_run_iterate(server_.get(), false);
    // Sleep
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = timeout * 10;
    select(0, NULL, NULL, NULL, &tv);
  }
  logger_.log_info("Shutting down");
}

void Server::abort() {
  abort_.store(true);
  logger_.log_debug("Abort triggered");
}

}  // namespace net
}  // namespace opcua