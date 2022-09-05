cmake_minimum_required(VERSION 3.22)
project(PCI)

set(CMAKE_CXX_STANDARD 17)
include_directories("3rdparty/jsoncpp/include")
include_directories("3rdparty/workflow/include")

link_directories("3rdparty/jsoncpp/lib")
link_directories("3rdparty/workflow/lib")

add_executable(PCI pavement.cpp pavement.h asphaltpavement.cpp asphaltpavement.h cementpavement.cpp cementpavement.h )

target_link_libraries(PCI jsoncpp workflow)

