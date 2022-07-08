#include "cementpavement.h"
#include <iostream>

bool isPointInRect(double x, double y, const std::vector<std::pair<double, double>> &Rect) {
    auto &A = Rect[0];
    auto &B = Rect[1];
    auto &C = Rect[2];
    auto &D = Rect[3];
    double a = (B.first - A.first) * (y - A.second) - (B.second - A.second) * (x - A.first);
    double b = (C.first - B.first) * (y - B.second) - (C.second - B.second) * (x - B.first);
    double c = (D.first - C.first) * (y - C.second) - (D.second - C.second) * (x - C.first);
    double d = (A.first - D.first) * (y - D.second) - (A.second - D.second) * (x - D.first);
    return (a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0);
}

int main() {
//    std::string segmentID("6");
//    std::string objectID("0");
//#ifndef _linux
//    std::string taskPath("/Volumes/dataRep2/processed/100614/");
//#else
//    string taskPath("/media/dataRep2/processed/100614/");
//#endif
//    pavement *p = new cementpavement(taskPath, segmentID, objectID);
//    p->loadAllPlate();
//    p->loadAllDisease();
//    p->calcPCI();
//    p->writeJson();
//    std::vector<std::pair<double, double>> Rect{
//
//            {30.542614,104.162672},
//            {30.542561,104.162767},
//            {30.542696,104.162877},
//            {30.542753,104.162780}
//    };
//
//    auto x=30.542662;
//    auto y=104.162778;

    std::vector<std::pair<double, double>> Rect{{30.542599, 104.162656},

                                                {30.542560, 104.162768},
                                                {30.542426, 104.162663},
                                                {30.542477, 104.162551}
    };
    auto x = 30.542538;
    auto y = 104.162664;
    std::cout << isPointInRect(x, y, Rect) << std::endl;

    return 0;
}
