cmake_minimum_required(VERSION 3.22)
project(PCI)

set(CMAKE_CXX_STANDARD 17)
include_directories("./jsoncpp/include")
include_directories("./jsoncpp/include/json")

link_directories("./jsoncpp/lib")

add_executable(PCI pavement.cpp pavement.h asphaltpavement.cpp asphaltpavement.h cementpavement.cpp cementpavement.h PCIService/common/mongoose.c PCIService/common/mongoose.h PCIService/main.cpp PCIService/handler/http_server.cpp PCIService/handler/http_server.h PCIService/handler/handler.cpp PCIService/handler/handler.h)
#add_executable(PCI main.cpp pavement.cpp pavement.h cementpavement.cpp cementpavement.h)
#add_executable(PCI main.cpp)

target_link_libraries(PCI jsoncpp)

