//
//  BattleController.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/19.
//
//
#include <cstdlib>
#include "BattleController.h"
#include "../LayerManager.h"
#include "../model/PlayerModel.h"



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
:isInAttack(false)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/effect/shouji_1.plist", "res/effect/shouji_1.pvr.ccz");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/effect/shouji_2.plist", "res/effect/shouji_2.pvr.ccz");
}

BattleController::~BattleController()
{
    
}

bool BattleController::isEnterBattle()
{
    srand((int)time(0));
    int x = rand() % 10;
    auto vo = CONFIG_TABLE->getConfigVo(1);
    if (x >= atoi(vo->data.c_str())) {
        return false;
    }
    return false;
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
    auto monster = getMonsterByIdx(mapId, point);
    p_monsterHp = monster.getHp();
    p_battleMonster = BattleMonster::create(p_monsterHp, monster.getAttack(), monster.getVelocity(), monster.res);
    p_battleView->addMonster(p_battleMonster);
    
    auto playerModel = PlayerModel::getInstance();
    p_userHp = playerModel->hp;
    p_battlePlayer = BattlePlayer::create(playerModel->hp, playerModel->attack, playerModel->velocity, "res/player/player.png");
    p_battleView->addPlayer(p_battlePlayer);
    
    p_elfs.clear();
    int attk = 6;
    for (int i = 0; i < 5; i++)
    {
        BattleElf *elf = BattleElf::create(40, 5, attk, "res/elf/elf_cat.png");
        p_userHp += 40;
        elf->index = i;
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

void BattleController::exitBattle()
{
    p_battleView->unschedule(CC_SCHEDULE_SELECTOR(BattleView::updateTimer));
    p_battleView->removeFromParentAndCleanup(true);
}

void BattleController::updateCallback(ObjType ot, AttackType at, int value, int index)
{
    if (ot == ObjType::MONSTER)
    {
        isInAttack = true;
        p_battleView->unschedule(CC_SCHEDULE_SELECTOR(BattleView::updateTimer));
        CCLOG("M［%d］怪物进行了攻击 攻击类型为［ %d ］输出伤害值为［ %d ］== %d 玩家血量剩余 ［%d］", ot, at, value, index, p_userHp);
        p_userHp -= value;
        p_battleMonster->showEffect();
    } else if (ot == ObjType::ELF)
    {
        CCLOG("E［%d］小精灵进行了攻击 攻击类型为［ %d ］输出伤害值为［ %d ］== %d 怪物血量剩余 ［%d］", ot, at, value, index, p_monsterHp);
        p_monsterHp -= value;
        for (BattleElf *elf : p_elfs)
        {
            if (elf->index == index)
            {
                elf->showEffect();
                break;
            }
        }
    } else if (ot == ObjType::PLAYER)
    {
        CCLOG("P［%d］主角进行了攻击 攻击类型为［ %d ］输出伤害值为［ %d ］== %d 怪物血量剩余 ［%d］", ot, at, value, index, p_monsterHp);
        p_monsterHp -= value;
        p_battlePlayer->showEffect();
    }
    
    //判断结果
    if (p_userHp <= 0)
    {
        CCLOG("你被怪物打败了，赶紧回家休息吧。");
        p_battleView->unschedule(CC_SCHEDULE_SELECTOR(BattleView::updateTimer));
        CCLOG("------->>>>退出战斗！");
        exitBattle();
    } else if (p_monsterHp <= 0) {
        CCLOG("恭喜你战胜了怪物！");
        p_battleView->unschedule(CC_SCHEDULE_SELECTOR(BattleView::updateTimer));
        CCLOG("------->>>>退出战斗！");
        exitBattle();
    }
}


void BattleController::updateTimer(float dt)
{
    if (p_battleMonster != nullptr && p_battleMonster->getParent() != nullptr)
    {
        p_battleMonster->update(dt, CC_CALLBACK_4(BattleController::updateCallback, this));
    }
    if (isInAttack) return;
    
    if (p_battlePlayer != nullptr && p_battlePlayer->getParent() != nullptr)
    {
        p_battlePlayer->update(dt, CC_CALLBACK_4(BattleController::updateCallback, this));
    }
    
    for (auto elf : p_elfs)
    {
        if (elf != nullptr && elf->getParent() != nullptr)
        {
            elf->update(dt, CC_CALLBACK_4(BattleController::updateCallback, this));
        }
    }
}

void BattleController::monsterAttack()
{
    auto animation = Animation::create();
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji1_01.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji1_02.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji1_03.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji1_04.png"));
    
    animation->setDelayPerUnit(2.8f / 14.0f);
    animation->setRestoreOriginalFrame(true);
    auto action = Animate::create(animation);
    
    auto callFun = CallFunc::create( CC_CALLBACK_0(BattleController::monsterAtkOver,this));
    auto sp = Sprite::create("res/default.png");
    p_battleView->effectNode_2->addChild(sp);
    sp->runAction(Sequence::create(action, callFun, NULL));
}

void BattleController::elfAttack()
{
    auto animation = Animation::create();
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji2_01.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji2_02.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji2_03.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji2_04.png"));
    
    animation->setDelayPerUnit(2.0f / 14.0f);
    animation->setRestoreOriginalFrame(true);
    auto action = Animate::create(animation);
    
    auto callFun = CallFunc::create( CC_CALLBACK_0(BattleController::elfAtkOver,this));
    auto sp = Sprite::create("res/default.png");
    p_battleView->effectNode_1->addChild(sp);
    sp->runAction(Sequence::create(action, callFun, NULL));
}

void BattleController::playerAttack()
{
    auto animation = Animation::create();
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji2_01.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji2_02.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji2_03.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shouji2_04.png"));
    
    animation->setDelayPerUnit(2.0f / 14.0f);
    animation->setRestoreOriginalFrame(true);
    auto action = Animate::create(animation);
    
    auto callFun = CallFunc::create( CC_CALLBACK_0(BattleController::elfAtkOver,this));
    auto sp = Sprite::create("res/default.png");
    p_battleView->effectNode_1->addChild(sp);
    sp->runAction(Sequence::create(action, callFun, NULL));
}


void BattleController::monsterAtkOver()
{
    p_battleView->effectNode_2->removeAllChildren();
    p_battleView->schedule(CC_SCHEDULE_SELECTOR(BattleView::updateTimer), 0.05, CC_REPEAT_FOREVER, 0);
    isInAttack = false;
}

void BattleController::elfAtkOver()
{
    p_battleView->effectNode_1->removeAllChildren();
}


void BattleController::playerAtkOver()
{
    p_battleView->effectNode_1->removeAllChildren();
}

MonsterModel BattleController::getMonsterByIdx(string mapId, Point p)
{
    MonsterModel monster;
    
    auto vo = MONSTER_TABLE->getMonsterVo(1);
    
    monster.setHp(vo->hp);
    monster.setName(vo->name);
    monster.setAttack(vo->attack);
    monster.setVelocity(vo->velocity);
    monster.res = vo->character_in;
    
    return monster;
}

