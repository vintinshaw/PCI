//
// Created by OaixNait on 2022/6/16.
//
#include <iostream>
#include <fstream>
#include <filesystem>
#include "pavement.h"

pavement::pavement(std::string &taskPath, std::string &segmentID, std::string &objectID) {
    for (const auto &entry: std::filesystem::directory_iterator(taskPath + "plate")) {
        this->m_allPlateJson.emplace_back(entry.path().string());
    }
    auto taskpathCopy = taskPath;
    for (const auto &entry: std::filesystem::directory_iterator(
            taskPath.append("image/disease/segment/").append(segmentID).append("/"))) {
        for (const auto &diseaseEntry: std::filesystem::directory_iterator(entry.path()))
            this->m_allDiseaseJson.emplace_back(diseaseEntry.path().string());
    }
    for (const auto &entry: std::filesystem::directory_iterator(
            taskpathCopy.append("image/disease/object/").append(objectID).append("/"))) {
        for (const auto &diseaseEntry: std::filesystem::directory_iterator(entry.path()))
            this->m_allDiseaseJson.emplace_back(diseaseEntry.path().string());
    }
    std::cout << "Init Path Successful" << std::endl;
    std::cout << taskPath << std::endl;
    std::cout << taskpathCopy << std::endl;
}

pavement::~pavement() = default;

void pavement::parseFile(const std::string &path, Json::Value &root) {
    std::ifstream ifs(path, std::ios::binary);
    Json::Reader reader;
    if (!reader.parse(ifs, root)) {
        std::cout << "parse error..." << std::endl;
        ifs.close();
    }
    if (ifs.is_open())
        ifs.close();
}

void pavement::writeJson(std::string &path) const {
    Json::Value root;
    parseFile(path, root);
    root["PCI"] = Json::Value(this->PCI);
    Json::FastWriter fw;
    std::ofstream os(path);
    if (!os.is_open())
        std::cout << "error：can not find or create the file which named " << path << "." << std::endl;
    os << fw.write(root);
    os.close();
}

void pavement::loadAllPlate() {
    Json::Value root;
    std::vector<std::pair<double, double>> vec;
    for (const auto &x: this->m_allPlateJson) {
        this->parseFile(x, root);
//        this->m_allPlate.emplace_back(root);
        vec.clear();
        for (auto &y: root["lassoReal"]) {
            vec.emplace_back(std::pair{y["latitude"].asDouble(), y["longitude"].asDouble()});
        }
//        std::sort(vec.begin(), vec.end(), [](auto &&x, auto &&y) {
//            return x.first < y.first && x.second < y.second;
//        });
        this->m_allPlatePosition.emplace_back(vec);
    }
    std::cout << "Load all plate Successful" << std::endl;
    std::cout << "Total plate num: " << this->m_allPlatePosition.size() << std::endl;
}

void pavement::loadAllDisease() {
    Json::Value root;
    disease d;
    for (const auto &x: this->m_allDiseaseJson) {
        if (EndWith(x, "json")) {
            this->parseFile(x, root);
//            this->m_allDisease.emplace_back(root);
            auto s = root["name"].asString();
            d.type = split(s);
            d.latitude = root["centerPoint"]["latitude"].asDouble();
            d.longitude = root["centerPoint"]["longitude"].asDouble();
            this->m_allDiseasePosition.emplace_back(d);
        }
    }
    std::cout << "Load all Disease Successful" << std::endl;
    std::cout << "Total disease num: " << this->m_allDiseasePosition.size() << std::endl;
}

bool pavement::EndWith(const std::string &str, const std::string &suffix) {
    if (str.size() < suffix.size()) {
        return false;
    }
    std::string tstr = str.substr(str.size() - suffix.size());
    if (tstr.length() == suffix.length()) {
        return std::equal(suffix.begin(), suffix.end(), tstr.begin(), [](char a, char b) {
            return tolower(a) == tolower(b);
        });
    } else {
        return false;
    }
}

std::string pavement::split(const std::string &inputStr) {
    std::vector<std::string> res;
    std::stringstream ss(inputStr);
    std::string str;
    while (getline(ss, str, '_'))
        res.emplace_back(str);
    return res[1];
}
