#include <iostream>
#include <open62541cpp/net/client/client.hpp>

int main() {
  opcua::net::Client client;
  client.connect("opc.tcp://localhost:8080");

  return 0;
}