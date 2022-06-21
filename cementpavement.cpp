//
// Created by OaixNait on 2022/6/16.
//

#include "cementpavement.h"


cementpavement::~cementpavement() = default;


void cementpavement::calcPCI() {
    for (const auto &onePlate: m_allPlatePosition) {
        std::vector<double> D(15, 0.0);
        std::vector<double> DV(15, 0.0);
        for (const auto &oneDis: m_allDiseasePosition) {
            double x = oneDis.latitude;
            double y = oneDis.longitude;
            std::string type = oneDis.type;
            if (isPointInRect(x, y, onePlate)) {
                D[disToIndex(type)]=100;
                break;
            }
        }
        for(int i=0;i<D.size();i++)
//            TODO
            DV[i]=1;
        std::sort(DV.begin(), DV.end());
        if(DV[13]>5){

        } else{
            accumulate

        }
    }

}

cementpavement::cementpavement(std::string &taskPath, std::string &algoID) : pavement(taskPath, algoID) {}

bool cementpavement::isPointInRect(double x, double y, const std::vector<std::pair<double, double>> &Rect) {
    auto A = Rect[0];
    auto B = Rect[1];
    auto C = Rect[2];
    auto D = Rect[3];
    double a = (B.first - A.first) * (y - A.second) - (B.second - A.second) * (x - A.first);
    double b = (C.first - B.first) * (y - B.second) - (C.second - B.second) * (x - B.first);
    double c = (D.first - C.first) * (y - C.second) - (D.second - C.second) * (x - C.first);
    double d = (A.first - D.first) * (y - D.second) - (A.second - D.second) * (x - D.first);
    if ((a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0))
        return true;
    else return false;
}

int cementpavement::disToIndex(const std::string &strname) {
    if (strname == "cracks" || strname == "durability cracks" || strname ==
                                                                 "contractibility crack" ||
        strname == "transverse cracks"
        || strname == "cracking" || strname == "longitudinalcracking" || strname ==
                                                                         "transversecracking") {
        return 1;
    } else if (strname == "corner fracture" || strname == "corner spalling"
               || strname == "cornerbreak" || strname == "cornerspalling") {
        return 2;
    } else if (strname == "seam broken"
               || strname == "jointsealdamage") {
        return 3;
    } else if (strname == "small patches" || strname == "large patcjes"
               || strname == "patch" || strname == "patches and digging patches") {
        return 4;
    } else {
        return 5;
    }

}
