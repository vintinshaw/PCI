//
// Created by OaixNait on 2022/6/16.
//

#ifndef PCI_CEMENTPAVEMENT_H
#define PCI_CEMENTPAVEMENT_H

#include "pavement.h"

class cementpavement :public pavement {
public:
    cementpavement(std::string &taskPath, std::string &algoID);

    void calcPCI() final;

    ~cementpavement() override;
};


#endif //PCI_CEMENTPAVEMENT_H
