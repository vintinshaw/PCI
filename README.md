# PCI机场跑道的道面状况指数计算
## 目前只实现了水泥路面的计算方法，沥青路面待实现。
## 简介
### 基类：pavement
基类实现了加载板块，加载病害功能，以及若干辅助函数
### 子类：cementpavement，用于水泥路面
### 子类：asphaltpavement，用于沥青路面
### 子类实现各自的PCI计算方法
## 使用
### 需要准备jsoncpp库
segmentID是语义分割算法的算法ID
objectID是目标检测算法的算法ID
taskPath是任务路径
```C++
pavement *p = new cementpavement(taskPath, segmentID, objectID);
    p->loadAllPlate();
    p->loadAllDisease();
    p->calcPCI();
//    p->writeJson();
```
# TODO 将PCI计算结果写回json
