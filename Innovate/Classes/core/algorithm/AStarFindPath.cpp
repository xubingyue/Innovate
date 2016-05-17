//
//  AStarFindPath.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/16.
//
//

#include "AStarFindPath.h"


AStarFindPath::AStarFindPath(TMXLayer *land, int mWidth, int mHeight)
:p_land(land)
,MAP_WIDTH(mWidth)
,MAP_HEIGHT(mHeight)
{
    p_openVec = {};
    p_closeVec = {};
}

AStarFindPath::~AStarFindPath()
{
    
}

vector<Vec2>* AStarFindPath::findPath(Vec2 start, Vec2 end, vector<Vec2> *pathVec)
{
    //起始点或者终点为空则路径为空
    if (p_land->getTileAt(start) == nullptr || p_land->getTileAt(end) == nullptr || start == end)
    {
        return nullptr;
    }
    p_openVec.clear();
    p_closeVec.clear();
    a_start = toAS(start);
    a_end = toAS(end);

    //开始寻路
    p_openVec.push_back(a_start);

    while (p_openVec.size() != 0)
    {
        //找出F值最小的点
        AS_Vec2 tempStart = getMinF(p_openVec);
        auto it = find(p_openVec.begin(), p_openVec.end(), tempStart);
        p_openVec.erase(it);
        p_closeVec.push_back(tempStart);
        
        //找出它相邻的点
        vector<AS_Vec2> vec = getNearVec(tempStart);
        for (auto av : vec) {
            //开启列表是否包含
            if (isExist(p_openVec, av))
            {
                foundPoint(tempStart, av);
            } else {
                notFoundPoint(tempStart, a_end, av);
            }
        }
        auto path = getAS(p_openVec, end);
        if (path.getCoord().x != -1)
        {
            return getPath(path, pathVec);
        }
    }
    auto path = getAS(p_closeVec, end);
    if (path.getCoord().x != -1)
    {
        return getPath(path, pathVec);
    }
    return nullptr;
}

//判断一个点 是否在地图内
bool AStarFindPath::isInMap(AS_Vec2 v)
{
    if (v.getCoord().x >= 0 && v.getCoord().x < MAP_WIDTH
        && v.getCoord().y >= 0 && v.getCoord().y < MAP_HEIGHT)
    {
        return true;
    }
    return false;
}

//判断一个点，是否可以行走
bool AStarFindPath::canMove(AS_Vec2 v)
{
    if (p_land->getTileAt(v.getCoord()) != nullptr
        && find(p_closeVec.begin(), p_closeVec.end(), v) == p_closeVec.end())
    {
        return true;
    }
    return false;
}

AS_Vec2 AStarFindPath::toAS(Vec2 v)
{
    AS_Vec2 as;
    as.setCoord(v);
//    as.parent = {-1, -1};
//    as.G = abs(a_start.getCoord().x - v.x) + abs(a_start.getCoord().y - v.y);
//    as.H = abs(a_end.getCoord().x - v.x) + abs(a_end.getCoord().y - v.y);
//    as.F = as.G + as.H;
    return as;
}

bool sortByAS(AS_Vec2 v1, AS_Vec2 v2)
{
    return v1.F < v2.F;
}

AS_Vec2& AStarFindPath::getMinF(vector<AS_Vec2> &vec)
{
    sort(vec.begin(), vec.end(), sortByAS);
    return vec[0];
}

vector<AS_Vec2> AStarFindPath::getNearVec(AS_Vec2 v)
{
    vector<AS_Vec2> vec;
    
    AS_Vec2 up = toAS({v.getCoord().x, v.getCoord().y - 1});
    AS_Vec2 down = toAS({v.getCoord().x, v.getCoord().y + 1});
    AS_Vec2 left = toAS({v.getCoord().x - 1, v.getCoord().y});
    AS_Vec2 right = toAS({v.getCoord().x + 1, v.getCoord().y});
    
    if (isInMap(up) && canMove(up))
    {
        vec.push_back(up);
    }
    if (isInMap(down) && canMove(down))
    {
        vec.push_back(down);
    }
    if (isInMap(left) && canMove(left))
    {
        vec.push_back(left);
    }
    if (isInMap(right) && canMove(right))
    {
        vec.push_back(right);
    }
    return vec;
}

//比较AS_Vec2
bool AStarFindPath::isExist(vector<AS_Vec2> vec, AS_Vec2 av)
{
    for (auto v : vec) {
        if (v.getCoord().x == av.getCoord().x
            && v.getCoord().y == av.getCoord().y)
        {
            return true;
        }
    }
    return false;
}

//获取
AS_Vec2 AStarFindPath::getAS(vector<AS_Vec2> vec, Vec2 av)
{
    for (auto v : vec) {
        if (v.getCoord().x == av.x
            && v.getCoord().y == av.y)
        {
            return v;
        }
    }
    AS_Vec2 tmp;
    tmp.setCoord({-1, -1});
    return tmp;
}

int AStarFindPath::calcG(AS_Vec2 temp, AS_Vec2 v)
{
    int G = abs(v.X - temp.X) + abs(v.Y - temp.Y);
    Vec2 nulV = {-1, -1};
    if (v.parent == nulV)
    {
        return G;
    } else {
        auto pa = getAS(p_openVec, v.parent);
        return pa.G + G;
    }
}

int AStarFindPath::calcH(AS_Vec2 end, AS_Vec2 curr)
{
    return abs(curr.X - end.X) + abs(curr.Y - end.Y);
}

void AStarFindPath::foundPoint(AS_Vec2 tmp, AS_Vec2 curr)
{
    int G = calcG(tmp, curr);
    if (G < curr.G)
    {
        curr.parent = tmp.getCoord();
        curr.G = G;
        curr.calcF();
    }
}

void AStarFindPath::notFoundPoint(AS_Vec2 tmp, AS_Vec2 end, AS_Vec2 curr)
{
    curr.parent = tmp.getCoord();
    curr.G = calcG(tmp, curr);
    curr.H = calcH(end, curr);
    curr.calcF();
    p_openVec.push_back(curr);
    
}

vector<Vec2>* AStarFindPath::getPath(AS_Vec2 as, vector<Vec2> *pathVec)
{
    if (as.getCoord().x != -1)
    {
        pathVec->push_back(as.getCoord());
        Vec2 nulV = {-1, -1};
        while (as.parent.x != -1) {
            as = getAS(p_closeVec, as.parent);
            pathVec->push_back(as.getCoord());
        }
    }
    reverse(pathVec->begin(), pathVec->end());
    return pathVec;
}





