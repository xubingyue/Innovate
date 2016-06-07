//
//  StageMapView.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/14.
//
//

#ifndef StageMapView_hpp
#define StageMapView_hpp

#include "cocos2d.h"
#include "2d/CCFastTMXTiledMap.h"
#include "MapObjBase.h"

//using namespace cocos2d::experimental;
using namespace cocos2d;

//地图块尺寸大小
#define TILED_SIZE 88
//主角tag
#define PLAYER_TAG 999

//各个层级名称定义
#define ROAD_LAYER "Road"
#define BG_LAYER "BG"
#define OBJ_LAYER "Key"


//对象层对象类型枚举
enum ObjectType {
    OT_PLAYER = 1,          //玩家
    OT_CRYSTAL = 2,         //水晶
    OT_DISPLAY = 3,         //非功能性显示（有遮挡关系的）
    OT_TRANSFER = 4,        //传送点
    OT_FUBEN = 5,           //副本
    OT_TRANSFER_FUBEN = 6,  //副本内传输点
    OT_TREASURE = 7,        //宝箱
    OT_MONSTER = 8          //副本内的明雷怪物
};

//点击地图移动时传递的对象（TOUCH_MAP_TO_MOVE）
class Touch2MoveData : public Ref
{
public:
    //目标点
    Point end;
    //建筑id
    int buildId = -1;
};


//class StageMapView : public experimental::TMXTiledMap
class StageMapView : public Node
{
public:
    
    static StageMapView* create(std::string str);
    
    bool init(std::string str);
    
    Vec2 tileCoordForPosition(const Vec2& position);
    // tile坐标转成瓦片格子中心的OpenGL坐标
    Vec2 positionForTileCoord(const Vec2& tileCoord);
    
    TMXTiledMap* getMap();
    //将对象add在地图上， p为在地图上的坐标
    void addToMap(Node *child, Point p);
    //将需要碰撞的对象add进集合
    void addObjToVec(Node *child);
    //将明雷怪物添加到集合中
    void addMonsterOjbToVec(Node *child);
    //打开地图上的建筑
    void openBuildingById(int buildId);
    //判断是否遇到怪物并返回怪物id
    int getMonsterByCoord(Point p);
    
    void onExit();
    
private:
    //touch
    bool onTouchBegan(Touch *touch, Event *unused_event);
    void onTouchMoved(Touch *touch, Event *unused_event);
    void onTouchEnded(Touch *touch, Event *unused_event);
    
private:
    TMXTiledMap* p_tmxMap;
    //建筑碰撞集合
    Vector<Node*> *p_mapObjVec;
    //明雷怪物碰撞集合
    Vector<Node*> *p_monsterObjVec;
};

#endif /* StageMapView_hpp */
