//
//  AStarFindPath.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/16.
//
//

#ifndef AStarFindPath_hpp
#define AStarFindPath_hpp

#include "cocos2d.h"
#include "2d/CCFastTMXTiledMap.h"

USING_NS_CC;
using namespace std;

struct AS_Vec2 {
    Vec2 parent = {-1, -1};
    int F = 0;
    int H = 0;
    int G = 0;
    int X = 0;
    int Y = 0;
    void setParent (Vec2 p) {
        parent.x = p.x;
        parent.y = p.y;
    };
    Vec2 getCoord()
    {
        return Vec2(X,Y);
    };
    void calcF()
    {
        F = G + H;
    };
    void setCoord(Vec2 v)
    {
        X = v.x;
        Y = v.y;
    };
    bool operator==(const AS_Vec2 &a)
    {
        return (X == a.X && Y == a.Y);
    }
};

class AStarFindPath {
public:
    AStarFindPath(TMXLayer *land, int mWidth, int mHeight);
    ~AStarFindPath();
    
    //移动到指定点
    vector<Vec2>* findPath(Vec2 start, Vec2 end, vector<Vec2> *pathVec);
    
private:
    //判断一个点 是否在地图内
    bool isInMap(AS_Vec2 v);
    
    //判断一个点，是否可以行走
    bool canMove(AS_Vec2 v);
    
    //将Vec2转换成AS_Vec2
    AS_Vec2 toAS(Vec2 v);
    
    //获得最小F值的点
    AS_Vec2& getMinF(vector<AS_Vec2> &vec);
    
    //获取相邻格
    vector<AS_Vec2> getNearVec(AS_Vec2 v);
    
    //比较AS_Vec2
    bool isExist(vector<AS_Vec2> vec, AS_Vec2 av);
    
    //获取
    AS_Vec2 getAS(vector<AS_Vec2> vec, Vec2 v);
    
    int calcG(AS_Vec2 temp, AS_Vec2 v);
    int calcH(AS_Vec2 end, AS_Vec2 curr);
    
    void foundPoint(AS_Vec2 tmp, AS_Vec2 curr);
    
    void notFoundPoint(AS_Vec2 tmp, AS_Vec2 end, AS_Vec2 curr);
    
    //获取最终路径
    vector<Vec2>* getPath(AS_Vec2 as, vector<Vec2> *pathVec);
    
private:
    TMXLayer *p_land;
    
    //关闭列表
    vector<AS_Vec2> p_closeVec;
    //开启列表
    vector<AS_Vec2> p_openVec;
    
    //地图的宽和高
    int MAP_WIDTH;
    int MAP_HEIGHT;
    
    //起始点于结束点
    AS_Vec2 a_start;
    AS_Vec2 a_end;


};

#endif /* AStarFindPath_hpp */
