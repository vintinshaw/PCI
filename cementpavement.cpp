//
// Created by OaixNait on 2022/6/16.
//
#include <numeric>
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
//            TODO DV[i]=???
//        1.将规定区域中道面出现的所有损坏类型的折减扣分值由大到小排序 形成一维数组
        std::sort(DV.begin(), DV.end(),std::greater<double>());
        double maxCDV=0;
//      否则
        if(DV[1]>5){
            double HDV=DV[0];
            double m=1.0+(9.0/95)*(100-HDV);
            int mCeil= ceil(m);
//           0~m中最小的折减扣分值，用3.4-2修正
            DV[mCeil-1]=(mCeil-m)*DV[mCeil-1];
//            （3
            int pos5=0;
            for(int i=mCeil-1;i>=0;i--){
                if(DV[i]>=5){
                    pos5=i;
                    break;
                }
            }
            while (DV[1]>5){
                int q=0;
                double maxCDV0=0;
                for(int i=0;i<mCeil;i++){
                    if(DV[i]>5)
                        q++;
                    maxCDV0+=DV[i];
                }
                //TODO 查表 CDV[i]=???
                DV[pos5]=5;
                pos5--;
                maxCDV=std::max()
            }


        } else{
//            2.如果{DVi(i=1 ~ n)}中{DVi >5的损坏数量不大于1则: MaxCDV=
            maxCDV=accumulate(DV.begin(),DV.end(),0);
        }
        double PCI=100-maxCDV;
    }

}

cementpavement::cementpavement(std::string &taskPath, std::string &algoID,std::string &objectID) : pavement(taskPath, algoID,objectID) {}

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
