//
//  BattleView.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/19.
//
//

#ifndef BattleView_hpp
#define BattleView_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "BattleObjBase.h"
#include "BattleElf.h"

using namespace std;
USING_NS_CC;


class BattleView : public cocos2d::Layer
{
public:
    static BattleView* create(int mapId, Vec2 point);
    
    BattleView();
    ~BattleView();
    
    bool init(int mapId, Vec2 point);
    
    virtual void onEnter() override;
    virtual void onExit() override;
    // 添加主角
    void addPlayer(BattleObjBase *player);
    // 添加小精灵
    void addElfs(Vector<BattleElf*> *elfs);
    // 添加怪物
    void addMonster(BattleObjBase *monster);
    //战斗时间轴
    void updateTimer(float dt);
    //开始战斗
    void startBattle();
private:
    //touch
    bool onTouchBegan(Touch *touch, Event *unused_event) override;
    void onTouchMoved(Touch *touch, Event *unused_event) override;
    void onTouchEnded(Touch *touch, Event *unused_event) override;
    
    void touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    
public:
    //特效位置
    Node *effectNode_1;
    Node *effectNode_2;
    //是否退出了战斗
    bool isExitBattle;
    
private:
    //ui跟节点
    Node *p_root;
    //主角站位点
    Node *p_playerNode;
    //怪物站位点
    Node *p_monsterNode;
    
};

#endif /* BattleView_hpp */
