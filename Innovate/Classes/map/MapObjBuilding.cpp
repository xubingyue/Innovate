//
//  MapObjBuilding.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/25.
//
//

#include "MapObjBuilding.h"

using namespace std;

MapObjBuilding* MapObjBuilding::create(std::string str)
{
    MapObjBuilding * ret = new (std::nothrow) MapObjBuilding();
    if (ret && ret->initWithFile(str))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

MapObjBuilding::MapObjBuilding()
{
    
}

MapObjBuilding::~MapObjBuilding()
{
    
}

void MapObjBuilding::initData(Point p, TMXLayer *land)
{
    p_buildVec = new vector<Point>();
    int w = this->getContentSize().width;
    int h = this->getContentSize().height;
    
    int i = w / TILED_SIZE;
    int j = h / TILED_SIZE;
    
    p_buildVec->push_back(p);
    
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            Point temp = Point(p.x + m, p.y - n);
            if(find(p_buildVec->begin(), p_buildVec->end(), temp) == p_buildVec->end())
            {
                p_buildVec->push_back(temp);
            }
        }
    }
    //缓存建筑周边的点
    p_aroundPointVec = new vector<Point>();
    for (Point v : *p_buildVec)
    {
//        Point up = Point(v.x, v.y - 1);
//        if (find(p_buildVec->begin(), p_buildVec->end(), up) == p_buildVec->end()
//            && land->getTileAt(up) != nullptr)
//        {
//            p_aroundPointVec->push_back(up);
//        }
        
        Point down = Point(v.x, v.y + 1);
        if (find(p_buildVec->begin(), p_buildVec->end(), down) == p_buildVec->end()
            && land->getTileAt(down) != nullptr)
        {
            p_aroundPointVec->push_back(down);
        }
        
        Point left = Point(v.x - 1, v.y);
        if (find(p_buildVec->begin(), p_buildVec->end(), left) == p_buildVec->end()
            && land->getTileAt(left) != nullptr)
        {
            p_aroundPointVec->push_back(left);
        }
        
        Point right = Point(v.x + 1, v.y);
        if (find(p_buildVec->begin(), p_buildVec->end(), right) == p_buildVec->end()
            && land->getTileAt(right) != nullptr)
        {
            p_aroundPointVec->push_back(right);
        }
    }
}

bool MapObjBuilding::isInBuilding(Point p)
{
    if(find(p_buildVec->begin(), p_buildVec->end(), p) == p_buildVec->end())
    {
        return false;
    }
    return true;
}

bool sortForAroundPoint(BuildAroundPoint v1, BuildAroundPoint v2)
{
    return v1.H < v2.H;
}

Point MapObjBuilding::getPathPoint(Point player)
{
    vector<BuildAroundPoint> tempVec;
    
    for(Point p : *p_aroundPointVec)
    {
        BuildAroundPoint bap;
        bap.p = p;
        bap.H = abs(player.x - p.x) + abs(player.y - p.y);
        tempVec.push_back(bap);
    }
    sort(tempVec.begin(), tempVec.end(), sortForAroundPoint);
    return tempVec[0].p;
}



