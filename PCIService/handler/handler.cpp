//
// Created by OaixNait on 2022/7/8.
//
#include "handler.h"
#include "json/json.h"

std::string test(std::string url, std::string body, mg_connection *c, OnRspCallback rsp_callback) {
    Json::Reader jReader;
    Json::Value jValue, resJValue;
    if (body.empty()) {
        //std::cout << "body empty! return: " << body << std::endl;
        return "body empty! return";
    }
    jReader.parse(body, jValue);
    resJValue["key"] = "plateStitch_Mercator";
    resJValue["res"] = 0;
    resJValue["param1"] = jValue["param1"].asString();

    Json::FastWriter writer;
    rsp_callback(c, writer.write(resJValue));
    return writer.write(resJValue);
}