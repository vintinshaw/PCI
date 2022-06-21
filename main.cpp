#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <sstream>
#include "cementpavement.h"

using namespace std;

decltype(auto) split(string &inputStr) {
    vector<string> res;
    if (inputStr.empty()) return res;
    std::stringstream ss(inputStr);
    std::string str;
    while (getline(ss, str, ','))
        res.emplace_back(str);
    return res;
}

int main() {
    string algoID("6");
#ifndef _linux
    string taskPath("/Volumes/dataRep2/processed/100614/");
#else
    string taskPath("/media/dataRep2/processed/100614/");
#endif
    for (const auto &entry : std::filesystem::directory_iterator(taskPath+"plate")){
        std::cout << entry.path() << std::endl;
    }
//    auto ss=taskPath.append("image/disease/segment/").append(algoID).append("/");
//    cout<<ss<<endl;
    for (const auto &entry: std::filesystem::directory_iterator(
            taskPath.append("image/disease/segment/").append(algoID).append("/"))) {
        for (const auto &diseaseEntry: std::filesystem::directory_iterator(entry.path()))
            std::cout << diseaseEntry.path() << std::endl;
    }

    pavement* p=new cementpavement(taskPath,algoID);
    p->loadAllPlate();
    p->loadAllDisease();
    p->calcPCI();
    p->writeJson();
    return 0;
}
