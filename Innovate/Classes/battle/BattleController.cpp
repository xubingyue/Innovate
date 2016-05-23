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
    int x = rand() % 100;
    CCLOG("随机概率是：%d", x);
    if (x >= 25) {
        return false;
    }
    return true;
}

void BattleController::showBattle(string mapId, Vec2 point)
{
    auto battleView = BattleView::create(mapId, point);
    auto battleLayer = LayerManager::getInstance()->getLayerByTag(LayerType::BATTLE_LAYER);
    battleLayer->addChild(battleView);
}