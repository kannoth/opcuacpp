#include <iostream>
#include <open62541cpp/net/client/client.hpp>

int main() {
  opcua::net::Client client;
  if (client.connect("localhost::8080"))
    std::cout << "Connected with server" << std::endl;
  else
    std::cout << "unable to connect with server" << std::endl;
  
  return 0;
}