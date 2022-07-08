//
// Created by OaixNait on 2022/7/8.
//

#ifndef PCI_HANDLER_H
#define PCI_HANDLER_H

#include <string>
#include "../common/mongoose.h"
#include "http_server.h"

std::string test(std::string url, std::string body, mg_connection *c, OnRspCallback rsp_callback);

#endif //PCI_HANDLER_H
