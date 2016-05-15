//
//  AStarPathSearch.h
//  Innovate
//
//  Created by YUEBINBIN on 16/5/15.
//
//

#ifndef AStarPathSearch_hpp
#define AStarPathSearch_hpp

#include "cocos2d.h"
#include "2d/CCFastTMXTiledMap.h"

USING_NS_CC;
using namespace std;

class AStarPathSearch {
public:
    AStarPathSearch(TMXLayer *land);
    ~AStarPathSearch();
    
    //初始化各种属性
    void init(std::string landName, int w, int h);
    
    //移动到指定点
    vector<Vec2>* move2TileCoord(Vec2 start, Vec2 end);
    
private:
    Vec2 findMinH(Vec2 start, Vec2 end);
    
private:
    TMXLayer *p_land;
    
    //关闭列表
    vector<Vec2> p_closeVec;
    //开启列表
    vector<Vec2> p_openVec;
    
    //地图的宽和高
    int MAP_WIDTH;
    int MAP_HEIGHT;
};

#endif /* AStarPathSearch_hpp */
