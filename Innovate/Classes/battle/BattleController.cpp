//
//  BattleController.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/19.
//
//

#include "BattleController.h"
#include "../LayerManager.h"
USING_NS_CC;
using namespace std;

static BattleController* _instance;

BattleController* BattleController::getInstance()
{
    if (_instance == nullptr) {
        _instance = new BattleController();
    }
    return _instance;
}

BattleController::BattleController()
{
    
}

BattleController::~BattleController()
{
    
}

bool BattleController::isEnterBattle()
{
    srand((int)time(0));
    int x = rand() % 10;
    CCLOG("随机概率是：%d", x);
    if (x >= 2) {
        return false;
    }
    return true;
}

void BattleController::showBattle(string mapId, Vec2 point)
{
    p_battleView = BattleView::create(mapId, point);
    auto battleLayer = LayerManager::getInstance()->getLayerByTag(LayerType::BATTLE_LAYER);
    battleLayer->addChild(p_battleView);
    initPosition(mapId, point);
}

void BattleController::initPosition(string mapId, Vec2 point)
{
    p_battleMonster = BattleMonster::create(50, 10, 6, "res/monster/monster.png");
    p_battleView->addMonster(p_battleMonster);
    
    p_battlePlayer = BattlePlayer::create(100, 15, 4, "res/player/player.png");
    p_battleView->addPlayer(p_battlePlayer);
    
    p_elfs.clear();
    int attk = 6;
    for (int i = 0; i < 5; i++)
    {
        BattleElf *elf = BattleElf::create(40, 5, attk, "res/elf/elf_cat.png");
        p_elfs.pushBack(elf);
        attk--;
    }
    p_battleView->addElfs(&p_elfs);
    startBattle();
}

void BattleController::startBattle()
{
    p_battleView->schedule(CC_SCHEDULE_SELECTOR(BattleView::updateTimer), 0.05, CC_REPEAT_FOREVER, 0);
}

void BattleController::updateCallback(ObjType ot, AttackType at, int value)
{
    
    if (ot == ObjType::MONSTER)
    {
        CCLOG("M［%d］怪物进行了攻击 攻击类型为［ %d ］输出伤害值为［ %d ］", ot, at, value);
    } else if (ot == ObjType::ELF)
    {
        CCLOG("E［%d］小精灵进行了攻击 攻击类型为［ %d ］输出伤害值为［ %d ］", ot, at, value);
    } else if (ot == ObjType::PLAYER)
    {
        CCLOG("P［%d］主角进行了攻击 攻击类型为［ %d ］输出伤害值为［ %d ］", ot, at, value);
    }
}


void BattleController::updateTimer(float dt)
{
    p_battlePlayer->update(dt, CC_CALLBACK_3(BattleController::updateCallback, this));
    p_battleMonster->update(dt, CC_CALLBACK_3(BattleController::updateCallback, this));
    
    for (auto elf : p_elfs)
    {
        elf->update(dt, CC_CALLBACK_3(BattleController::updateCallback, this));
    }
}






