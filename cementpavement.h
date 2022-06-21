//
// Created by OaixNait on 2022/6/16.
//

#ifndef PCI_CEMENTPAVEMENT_H
#define PCI_CEMENTPAVEMENT_H

#include "pavement.h"

class cementpavement : public pavement {
public:
    cementpavement(std::string &taskPath, std::string &algoID);

    static bool isPointInRect(double x, double y, const std::vector<std::pair<double, double>> &Rect);

    stacic int disToIndex(const std::string &str);

    void calcPCI() final;

    ~cementpavement() override;

private:

};


#endif //PCI_CEMENTPAVEMENT_H
