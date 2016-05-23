//
//  BattleObjBase.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/20.
//
//

#include "BattleObjBase.h"

BattleObjBase* BattleObjBase::create(int hp, int att, float vel, float velProcess)
{
    BattleObjBase * ret = new (std::nothrow) BattleObjBase(hp, att, vel, velProcess);
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

BattleObjBase::BattleObjBase(int hp, int att, float vel, float velProcess)
:p_HP(hp)
,p_ATTACK(att)
,p_VELOCITY(vel)
,p_velcity_process(velProcess)
{
    
}

BattleObjBase::~BattleObjBase()
{
    
}

void BattleObjBase::update(float dt, const BattleObjCallback& callback)
{
    p_velcity_process += dt;
    if (p_velcity_process >= p_VELOCITY)
    {
        p_velcity_process = 0.0f;
        callback(1, AttackType::HURT, 20);
    }
}

void BattleObjBase::setHP(int hp)
{
    p_HP = hp;
}

int BattleObjBase::getHP()
{
    return p_HP;
}

void BattleObjBase::setAttack(int attack)
{
    p_ATTACK = attack;
}

int BattleObjBase::getAttack()
{
    return p_ATTACK;
}

void BattleObjBase::setVelocity(float vel)
{
    p_VELOCITY = vel;
}

float BattleObjBase::getVelocity()
{
    return getVelocity();
}



