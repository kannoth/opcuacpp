#include<iostream>
#include<open62541cpp/net/server/server.hpp>


int main (){
    opcua::net::Server server(8080);
    server.run();
    return 0;
}