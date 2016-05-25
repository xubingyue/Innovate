#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "RoleSprite.h"
//#include "AStarPathSearch.h"
#include "AStarFindPath.h"
#include "StageMapView.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
//    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    //初始化地图
    void initWorldMap(std::string id = "1");
    //初始化人物在屏幕上的位置
    void initPosition();
    //更新地图移动
    void updateMapByPlayer(float dt);
    //人物层级排序
    void updatePlayerZorder(float dt);
    //移动一步结束后的回调
    void moveCallBack();
    //移动一步结束后的回调
    void movesCallBack();
    
    void touch2Move(Ref *obj);
    
private:
    //角色
    RoleSprite *m_player;
    //A*寻路算法
    AStarFindPath* p_aStar;
    //当前地图
    StageMapView *p_map;
    //player上一帧位置
    Point p_prePoint;
    //角色是否在寻路中
    bool p_isFinding;
    //队列中的目标点
    Point p_targetPoint;
    //目标点 队列是否为空
    bool p_isNull;
    //保存色值
    Color3B p_color;
    Sprite *p_sp;
};

#endif // __HELLOWORLD_SCENE_H__
