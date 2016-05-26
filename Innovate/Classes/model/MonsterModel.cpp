//
//  MonsterModel.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/25.
//
//

#include "MonsterModel.h"

MonsterModel::MonsterModel()
:velo_buff(0)
{
    
}

MonsterModel::~MonsterModel()
{
    
}


void MonsterModel::setName(string name)
{
    this->name = name;
}

string MonsterModel::getName()
{
    return name;
}

void MonsterModel::setHp(int hp)
{
    this->hp = hp;
}

int MonsterModel::getHp()
{
    return hp;
}

void MonsterModel::setAttack(int atk)
{
    this->attack = atk;
}
int MonsterModel::getAttack()
{
    return attack;
}

void MonsterModel::setVelocity(float velocity)
{
    this->velocity = velocity;
}

float MonsterModel::getVelocity()
{
    //公式： 10*速度^-1
    return 10 * pow(velocity + velo_buff, -1);
}

void MonsterModel::setVeloBuff(float vb)
{
    this->velo_buff = vb;
}

float MonsterModel::getVeloBuff()
{
    return velo_buff;
}




