//
//  BattleElf.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/23.
//
//

#include "BattleElf.h"
#include "../BattleController.h"


BattleElf* BattleElf::create(int hp, int att, float vel, std::string cha, float velProcess)
{
    BattleElf * ret = new (std::nothrow) BattleElf(hp, att, vel, velProcess);
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

BattleElf::BattleElf()
{
    
}

BattleElf::BattleElf(int hp, int att, float vel, float velProcess)
{
    setHP(hp);
    setAttack(att);
    setVelocity(vel);
    setVelPro(velProcess);
}

void BattleElf::update(float dt, const BattleObjCallback& callback)
{
    setVelPro(getVelPro() + dt);
    if (getVelPro() >= getVelocity())
    {
        setVelPro(0.0f);
        callback(ObjType::ELF, AttackType::HURT, getAttack(), index);
    }
}

bool BattleElf::operator==(const BattleElf &elf)
{
    return index == elf.index;
}

void BattleElf::showEffect()
{
    auto animation = Animation::create();
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gongji01.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gongji02.png"));
    
    animation->setDelayPerUnit(2.8f / 14.0f);
    animation->setRestoreOriginalFrame(true);
    auto action = Animate::create(animation);
    
    auto callFun = CallFunc::create( CC_CALLBACK_0(BattleElf::showEffectOver,this));
    
    selfSp->runAction(Sequence::create(action, callFun, NULL));
}

void BattleElf::showEffectOver()
{
    BattleController::getInstance()->elfAttack();
}


BattleElf::~BattleElf()
{
    
}