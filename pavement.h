//
// Created by OaixNait on 2022/6/16.
//

#ifndef PCI_PAVEMENT_H
#define PCI_PAVEMENT_H

#include <vector>
#include <string>
#include "json/json.h"

class pavement {
public:
    pavement(std::string &taskPath, std::string &algoID);

    virtual void loadAllPlate();

    virtual void loadAllDisease();

    virtual void calcPCI() = 0;

    static void parseFile(const std::string &path, Json::Value &root);

    static bool EndWith(const std::string &str, const std::string &suffix);

    void writeJson(std::string &path) const;

    virtual ~pavement();

private:

    double PCI = 0;
    std::vector<std::string> m_allPlateJson;
    std::vector<std::string> m_allDiseaseJson;
    Json::Value m_plate;
    std::vector<Json::Value> m_allPlate;
    Json::Value m_disease;
    std::vector<Json::Value> m_allDisease;
};


#endif //PCI_PAVEMENT_H
