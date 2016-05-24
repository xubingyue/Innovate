//
//  BattlePlayer.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/23.
//
//

#include "BattlePlayer.h"

BattlePlayer* BattlePlayer::create(int hp, int att, float vel, std::string cha, float velProcess)
{
    BattlePlayer * ret = new (std::nothrow) BattlePlayer(hp, att, vel, velProcess);
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

BattlePlayer::BattlePlayer()
{
    
}

BattlePlayer::BattlePlayer(int hp, int att, float vel, float velProcess)
{
    setHP(hp);
    setAttack(att);
    setVelocity(vel);
    setVelPro(velProcess);
}


void BattlePlayer::update(float dt, const BattleObjCallback& callback)
{
    setVelPro(getVelPro() + dt);
    if (getVelPro() >= getVelocity())
    {
        setVelPro(0.0f);
        callback(ObjType::PLAYER, AttackType::HURT, getAttack());
    }
}


BattlePlayer::~BattlePlayer()
{
    
}