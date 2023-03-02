#include <iostream>
#include <open62541cpp/net/client/client.hpp>

int main() {
  opcua::net::Client client;
  client.connect("localhost::8080");

  return 0;
}