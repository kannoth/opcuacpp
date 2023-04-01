#include <iostream>
#include <open62541cpp/common/exception/exceptions_extended.hpp>
#include <open62541cpp/net/client/client.hpp>
#include <open62541cpp/net/client/client_exceptions.hpp>

namespace opcua {
namespace net {

void UA_ClientDeleter::operator()(UA_Client* client) {
  if (client != nullptr) UA_Client_delete(client);
}

Client::Client() : client_(UA_Client_new()) {
  // UA_ClientConfig clientConfig;
  UA_ClientConfig_setDefault(UA_Client_getConfig(client_.get()));
}

void Client::connect(const type::ua_string& endpoint) {
  UA_StatusCode status = UA_Client_connect(client_.get(), endpoint.c_str());
  diag::throw_from_status(status);
}

}  // namespace net
}  // namespace opcua
