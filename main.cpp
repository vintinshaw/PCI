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
    string segmentID("6");
    string objectID("0");
#ifndef _linux
    string taskPath("/Volumes/dataRep2/processed/100614/");
#else
    string taskPath("/media/dataRep2/processed/100614/");
#endif
//    enum color_set1 {RED, BLUE, WHITE, BLACK};


//    pavement* p=new cementpavement(taskPath,segmentID,objectID);
//    p->loadAllPlate();
//    p->loadAllDisease();
//    p->calcPCI();
//    p->writeJson();
    return 0;
}
