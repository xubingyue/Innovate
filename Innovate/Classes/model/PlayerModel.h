//
//  PlayerModel.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/30.
//
//

#ifndef PlayerModel_hpp
#define PlayerModel_hpp

#include "ModelBase.h"

class PlayerModel : public ModelBase
{
public:
    
    static PlayerModel* getInstance();
    
    /*
     * 初始化玩家数据
     * 等级 血量 攻击 速度 暗攻 暗抗 火攻 火抗 风攻 风抗 土攻 土抗 恢复 吸血
     */
    void init(int lv, int hp, int atk, float velo,
              int da, int dr, int fa, int fr, int wa, int skill,
              int wr, int sa, int sr, int recover, int absorb);
    
    PlayerModel();
    ~PlayerModel();
    
    
public:
    int level;
    int hp;
    int attack;
    float velocity;
    int skill;
    int darkAtk;
    int darkRst;
    int fireAtk;
    int fireRst;
    int windAtk;
    int windRst;
    int soilAtk;
    int soilRst;
    int recover;
    int absorb;
};

#endif /* PlayerModel_hpp */
