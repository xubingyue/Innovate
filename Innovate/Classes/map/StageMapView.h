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

//using namespace cocos2d::experimental;
using namespace cocos2d;

#define PLAYER_TAG 99

//对象层对象类型枚举
enum ObjectType {
    OT_PLAYER = 1,     //玩家
    OT_BUILDING = 2,   //建筑
    OT_DISPLAY = 3     //非功能性显示（有遮挡关系的）
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
    
private:
    //touch
    bool onTouchBegan(Touch *touch, Event *unused_event);
    void onTouchMoved(Touch *touch, Event *unused_event);
    void onTouchEnded(Touch *touch, Event *unused_event);
    
private:
    TMXTiledMap* p_tmxMap;

};

#endif /* StageMapView_hpp */
