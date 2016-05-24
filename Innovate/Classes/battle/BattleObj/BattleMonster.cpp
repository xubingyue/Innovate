//
//  BattleMonster.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/23.
//
//

#include "BattleMonster.h"
#include "../BattleController.h"

BattleMonster* BattleMonster::create(int hp, int att, float vel, std::string cha, float velProcess)
{
    BattleMonster * ret = new (std::nothrow) BattleMonster(hp, att, vel, velProcess);
    if (ret && ret->init(cha))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

BattleMonster::BattleMonster()
{
    
}

BattleMonster::BattleMonster(int hp, int att, float vel, float velProcess)
{
    setHP(hp);
    setAttack(att);
    setVelocity(vel);
    setVelPro(velProcess);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/effect/attackEffect.plist", "res/effect/attackEffect.pvr.ccz");
}

void BattleMonster::update(float dt, const BattleObjCallback& callback)
{
    setVelPro(getVelPro() + dt);
    if (getVelPro() >= getVelocity())
    {
        setVelPro(0.0f);
        callback(ObjType::MONSTER, AttackType::HURT, getAttack(), 0);
    }
}

void BattleMonster::showEffect()
{
    auto animation = Animation::create();
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gongji01.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gongji02.png"));

    animation->setDelayPerUnit(2.8f / 14.0f);
    animation->setRestoreOriginalFrame(true);
    auto action = Animate::create(animation);
    
    auto callFun = CallFunc::create( CC_CALLBACK_0(BattleMonster::showEffectOver,this));
    
    selfSp->runAction(Sequence::create(action, callFun, NULL));
}

void BattleMonster::showEffectOver()
{
    BattleController::getInstance()->monsterAttack();
}

BattleMonster::~BattleMonster()
{
    
}