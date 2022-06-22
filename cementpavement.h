//
// Created by OaixNait on 2022/6/16.
//

#ifndef PCI_CEMENTPAVEMENT_H
#define PCI_CEMENTPAVEMENT_H

#include "pavement.h"

class cementpavement : public pavement {
public:
    cementpavement(std::string &taskPath, std::string &segmentID, std::string &objectID);

    static bool isPointInRect(double x, double y, const std::vector<std::pair<double, double>> &Rect);

    static int disToIndex(const std::string &str);

    void calcPCI() final;

    ~cementpavement() override;

private:
    const std::vector<std::pair<double, double>> diseaseCurve{
            {0, 57.6714},//横向、纵向、斜向裂缝
            {0, 72.5366},//角隅断裂
            {0, 83.5281},//破碎板或交叉裂缝
            {0, 56.5763},//沉陷或错台
            {0, 100},//胀裂
            {0, 7},//嵌缝料损坏
            {0, 36.4447},//接缝破碎
            {0, 51.6087},//唧泥或板底脱空
            {0, 49.3864},//耐久性裂缝
            {0, 14.026},//收缩裂缝
            {0, 21.6755},//坑洞
            {0, 39.1201},//起皮、龟裂、细微裂缝
            {0, 28.5925},//板角剥落
            {0, 21.6533},//小补丁
            {0, 49.2344}//大补丁
    };
    const std::vector<std::vector<double>> QCureve{
            {0, 1, 0},//q=1
            {-0.0012, 0.9859, -3.2434},//q=2
            {-0.0012, 0.8996, -3.6211},//q=3
            {-0.0017, 0.9038, -5.2561},//q=4
            {-0.0018, 0.9068, -6.587},//q=5
            {-0.0016, 0.8661, -5.8492},//q=6
            {-0.0015, 0.8244, -5.2739},//q=7
            {-0.0014, 0.7756, -4.2814}//q=8
    };
};


#endif //PCI_CEMENTPAVEMENT_H
