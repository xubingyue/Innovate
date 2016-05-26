//
//  MapObjBuilding.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/25.
//
//

#ifndef MapObjBuilding_hpp
#define MapObjBuilding_hpp

#include "MapObjBase.h"

struct BuildAroundPoint
{
    Point p;
    int H;
};


class MapObjBuilding : public MapObjBase
{
public:
    static MapObjBuilding* create(std::string str);
    
    MapObjBuilding();
    ~MapObjBuilding();
    //初始化坐标点数据
    void initData(Point p, TMXLayer *land);
    //判断一个点是否在建筑上
    bool isInBuilding(Point p);
    Point getPathPoint(Point p);
private:
    //建筑所占的坐标点
    std::vector<Point> *p_buildVec;
    //建筑周围的坐标点
    std::vector<Point> *p_aroundPointVec;
};


#endif /* MapObjBuilding_hpp */
