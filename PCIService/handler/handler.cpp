//
// Created by OaixNait on 2022/7/8.
//
#include <iostream>
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

    std::string strPrjDir = jValue["param1"].asString();
    std::string strPrjTaskList = jValue["param2"].asString();
    std::string strName = jValue["param3"].asString();
    std::string strX = jValue["param4"].asString();
    std::string strY = jValue["param5"].asString();
    std::string strW = jValue["param6"].asString();
    std::string strH = jValue["param7"].asString();
    std::cout << strPrjDir << std::endl;
    resJValue["key"] = "plateStitch_Mercator";
    resJValue["res"] = 0;
    rsp_callback(c, resJValue.toStyledString());
    return resJValue.toStyledString();
}