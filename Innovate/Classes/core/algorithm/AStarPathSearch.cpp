//
//  AStarPathSearch.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/15.
//
//

#include "AStarPathSearch.h"


AStarPathSearch::AStarPathSearch(TMXLayer *land)
{
    p_land = land;
}

AStarPathSearch::~AStarPathSearch ()
{
    
}

void AStarPathSearch::init(string name, int w, int h)
{
    MAP_WIDTH = w;
    MAP_HEIGHT = h;
}

vector<Vec2>* AStarPathSearch::move2TileCoord(Vec2 start, Vec2 end)
{
    //起始点或者终点为空则路径为空
    if (p_land->getTileAt(start) == nullptr || p_land->getTileAt(end) == nullptr)
    {
        return nullptr;
    }
    
    p_openVec = {};
    p_closeVec = {};
    
    p_closeVec.push_back(start);
    
    //开始寻路
    Vec2 nullVec = {-1, -1};
    //处理下一个点
    while (start != end) {
        Vec2 tmp = findMinH(start, end);
        if (tmp != nullVec)
        {
            auto it = find(p_openVec.begin(), p_openVec.end(), tmp);
            p_openVec.erase(it);
            p_closeVec.push_back(tmp);
            start = tmp;
        } else {
            CCLOG("此路不通");
        }
    }
    
    CCLOG("dlsjdflsdfjs");
    
    return &p_closeVec;
}

Vec2 AStarPathSearch::findMinH(Vec2 start, Vec2 end)
{
    Vec2 up = {start.x, start.y - 1};
    Vec2 down = {start.x, start.y + 1};
    Vec2 left = {start.x - 1, start.y};
    Vec2 right = {start.x + 1, start.y};
    
    int min = -1;
    Vec2 minV = {-1, -1};
    if (find(p_closeVec.begin(), p_closeVec.end(), up) == p_closeVec.end()
        && up.x >= 0 && up.x < MAP_WIDTH
        && up.y >= 0 && up.y < MAP_HEIGHT
        && p_land->getTileAt(up) != nullptr)
    {
        p_openVec.push_back(up);
        min = abs(end.x - up.x) + abs(end.y - up.y);
        minV = up;
    }
    if (find(p_closeVec.begin(), p_closeVec.end(), down) == p_closeVec.end()
        && down.x >= 0 && down.x < MAP_WIDTH
        && down.y >= 0 && down.y < MAP_HEIGHT
        && p_land->getTileAt(down) != nullptr)
    {
        p_openVec.push_back(down);
        int tmp = abs(end.x - down.x) + abs(end.y - down.y);
        if (tmp < min || min == -1)
        {
            min = tmp;
            minV = down;
        }
    }
    if (find(p_closeVec.begin(), p_closeVec.end(), left) == p_closeVec.end()
        && left.x >= 0 && left.x < MAP_WIDTH
        && left.y >= 0 && left.y < MAP_HEIGHT
        && p_land->getTileAt(left) != nullptr)
    {
        p_openVec.push_back(left);
        int tmp = abs(end.x - left.x) + abs(end.y - left.y);
        if (tmp < min || min == -1)
        {
            min = tmp;
            minV = left;
        }
    }
    if (find(p_closeVec.begin(), p_closeVec.end(), right) == p_closeVec.end()
        && right.x >= 0 && right.x < MAP_WIDTH
        && right.y >= 0 && right.y < MAP_HEIGHT
        && p_land->getTileAt(right) != nullptr)
    {
        p_openVec.push_back(right);
        int tmp = abs(end.x - right.x) + abs(end.y - right.y);
        if (tmp < min || min == -1)
        {
            min = tmp;
            minV = right;
        }
    }
    return minV;
}