//
//  BattleMonster.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/23.
//
//

#include "BattleMonster.h"

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
}

void BattleMonster::update(float dt, const BattleObjCallback& callback)
{
    setVelPro(getVelPro() + dt);
    if (getVelPro() >= getVelocity())
    {
        setVelPro(0.0f);
        callback(ObjType::MONSTER, AttackType::HURT, getAttack());
    }
}

BattleMonster::~BattleMonster()
{
    
}