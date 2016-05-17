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
    void initWorldMap(std::string id = "1");
    void touch2Move(Ref *obj);
    
private:
    //角色
    RoleSprite *m_player;
    //A*寻路算法
    AStarFindPath* p_aStar;
    //当前地图
    StageMapView *p_map;
    
};

#endif // __HELLOWORLD_SCENE_H__
