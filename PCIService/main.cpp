//
// Created by OaixNait on 2022/7/8.
//

#include <iostream>
#include <memory>
#include "handler/http_server.h"
#include "handler/handler.h"

// 初始化HttpServer静态类成员
mg_serve_http_opts HttpServer::s_server_option;
std::string HttpServer::s_web_dir = "./web";
std::unordered_map<std::string, ReqHandler> HttpServer::s_handler_map;
std::unordered_set<mg_connection *> HttpServer::s_websocket_session_set;

int main(int argc, char *argv[]) {
    std::string port = "7999";
    auto http_server = std::make_shared<HttpServer>();
    http_server->Init(port);
    // add handler
    http_server->AddHandler("/api/test", test);
    http_server->Start();
    return 0;
}