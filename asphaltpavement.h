//
// Created by OaixNait on 2022/6/16.
//

#ifndef PCI_ASPHALTPAVEMENT_H
#define PCI_ASPHALTPAVEMENT_H

#include "pavement.h"
class asphaltpavement: pavement{
public:
    asphaltpavement(std::string &strPrjDir, std::vector<std::string> &vecInPath);

    virtual ~asphaltpavement();
};


#endif //PCI_ASPHALTPAVEMENT_H
