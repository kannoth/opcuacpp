#include <iostream>
#include <open62541cpp/net/client/client.hpp>
#include <open62541cpp/net/client/client_exceptions.hpp>

namespace opcua {
namespace net {

void UA_ClientDeleter::operator()(UA_Client* client){
    if(client != nullptr) UA_Client_delete(client);
}

Client::Client(): client_(UA_Client_new()){
    // UA_ClientConfig clientConfig;
    UA_ClientConfig_setDefault(UA_Client_getConfig(client_.get()));
}

bool Client::connect(std::string endpoint){
    UA_StatusCode status = UA_Client_connect(client_.get(), endpoint.c_str());
    if(status != UA_STATUSCODE_GOOD) 
        return true; // return status code
    return false;   
}

bool Client::abort(){
    return false;
}

}  // namespace net
}  // namespace opcua
