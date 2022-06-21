//
// Created by OaixNait on 2022/6/16.
//

#ifndef PCI_PAVEMENT_H
#define PCI_PAVEMENT_H

#include <vector>
#include <string>
#include "json/json.h"
//struct plate{
//    std::pair<double,double> A;
//    std::pair<double,double> B;
//};
struct disease {
    std::string type;
    double longitude;
    double latitude;
};

class pavement {
public:
    pavement(std::string &taskPath, std::string &algoID,std::string &objectID);

    virtual void loadAllPlate();

    virtual void loadAllDisease();

    virtual void calcPCI() = 0;

    static void parseFile(const std::string &path, Json::Value &root);

    static bool EndWith(const std::string &str, const std::string &suffix);

    static std::string split(const std::string &inputStr);

    void writeJson(std::string &path) const;

    virtual ~pavement();

protected:
    double PCI = 0;
    std::vector<std::string> m_allPlateJson;
    std::vector<std::string> m_allDiseaseJson;
    std::vector<Json::Value> m_allPlate;
    std::vector<Json::Value> m_allDisease;
    std::vector<std::vector<std::pair<double, double>>> m_allPlatePosition;
    std::vector<disease> m_allDiseasePosition;
};


#endif //PCI_PAVEMENT_H
