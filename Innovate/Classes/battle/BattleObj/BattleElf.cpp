//
//  BattleElf.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/23.
//
//

#include "BattleElf.h"


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
        callback(ObjType::ELF, AttackType::HURT, getAttack());
    }
}

BattleElf::~BattleElf()
{
    
}