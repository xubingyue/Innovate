//
//  BattleController.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/19.
//
//

#ifndef BattleController_hpp
#define BattleController_hpp

#include "cocos2d.h"
#include "BattleView.h"
#include "BattleMonster.h"
#include "BattlePlayer.h"
#include "BattleElf.h"
#include "DataManager.h"
#include "MonsterModel.h"

class BattleController : public Ref
{
public:
    static BattleController* getInstance();
    
    BattleController();
    ~BattleController();
  
    //判断是否进入战斗
    bool isEnterBattle();
    
    //打开战斗界面
    void showBattle(std::string mapId, cocos2d::Vec2 point);
    //战斗时间轴
    void updateTimer(float dt);
    //怪物闪影攻击
    void monsterAttack();
    void elfAttack();
    void playerAttack();
    
    //开始战斗
    void startBattle();
    //退出战斗
    void exitBattle();
    
public:
    //是否在战斗状态
    bool isInAttack;

private:
    //初始化战斗角色
    void initPosition(std::string mapId, Vec2 point);
    //时间轴回调
    void updateCallback(ObjType ot, AttackType at, int value, int index = 0);
    //怪物攻击结束
    void monsterAtkOver();
    //精灵攻击结束
    void elfAtkOver();
    //玩家攻击结束
    void playerAtkOver();
    //根据场景位置获取怪物
    MonsterModel getMonsterByIdx(string mapId, Point p);
    
private:
    //战斗场景
    BattleView *p_battleView;
    //怪物
    BattleMonster *p_battleMonster;
    //主角
    BattlePlayer *p_battlePlayer;
    //精灵数组
    Vector<BattleElf*> p_elfs;
    
    int p_userHp;
    int p_monsterHp;
};

#endif /* BattleController_hpp */
