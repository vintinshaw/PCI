#include "cementpavement.h"

int main() {
    std::string segmentID("6");
    std::string objectID("0");
#ifndef _linux
    std::string taskPath("/Volumes/dataRep2/processed/100614/");
#else
    string taskPath("/media/dataRep2/processed/100614/");
#endif
    pavement *p = new cementpavement(taskPath, segmentID, objectID);
    p->loadAllPlate();
    p->loadAllDisease();
    p->calcPCI();
//    p->writeJson();
    return 0;
}
