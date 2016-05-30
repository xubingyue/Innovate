//
//  PlayerModel.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/30.
//
//

#include "PlayerModel.h"


static PlayerModel* _instance = nullptr;

PlayerModel* PlayerModel::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new PlayerModel();
    }
    return _instance;
}

/*
 * 初始化玩家数据
 * 等级 血量 攻击 速度 暗攻 暗抗 火攻 火抗 风攻 风抗 土攻 土抗 恢复 吸血
 */
void PlayerModel::init(int lv, int hp, int atk, float velo,
          int da, int dr, int fa, int fr, int wa,
          int wr, int sa, int sr, int recover, int absorb)
{
    this->level = lv;
    this->hp = hp;
    this->attack = atk;
    this->velocity = velo;
    this->darkAtk = da;
    this->darkRst = dr;
    this->fireAtk = fa;
    this->fireRst = fr;
    this->windAtk = wa;
    this->windRst = wr;
    this->soilAtk = sa;
    this->soilRst = sr;
    this->recover = recover;
    this->absorb = absorb;
}

PlayerModel::PlayerModel()
{
    
}
PlayerModel::~PlayerModel()
{
    
}


