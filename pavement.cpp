//
// Created by OaixNait on 2022/6/16.
//
#include <iostream>
#include <fstream>
#include "pavement.h"

pavement::pavement(std::string &taskPath, std::string &algoID) {
    for (const auto &entry: std::filesystem::directory_iterator(taskPath + "plate")) {
        this->m_allPlateJson.emplace_back(entry.path().string());
    }
    for (const auto &entry: std::filesystem::directory_iterator(
            taskPath.append("image/disease/segment/").append(algoID).append("/"))) {
        for (const auto &diseaseEntry: std::filesystem::directory_iterator(entry.path()))
            this->m_allDiseaseJson.emplace_back(diseaseEntry.path().string());
    }
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
    for (const auto &x: this->m_allPlateJson) {
        this->parseFile(x, root);
        this->m_allPlate.emplace_back(root);
    }
}

void pavement::loadAllDisease() {
    Json::Value root;
    for (const auto &x: this->m_allDiseaseJson) {
        if (EndWith(x, "json")) {
            this->parseFile(x, root);
            this->m_allDisease.emplace_back(root);
        }
    }
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