//
//  BattleObjBase.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/20.
//
//

#ifndef BattleObjBase_hpp
#define BattleObjBase_hpp

#include "cocos2d.h"

USING_NS_CC;

enum AttackType {
    HURT,
    RECOVER
};

enum ObjType {
    PLAYER,
    ELF,
    MONSTER
};

typedef std::function<void(ObjType, AttackType, int)> BattleObjCallback;

/**
 * 战斗对象的基类
 */
class BattleObjBase : public Node
{
public:
    
    BattleObjBase() = default;
    BattleObjBase(int hp, int att, float vel, float velProcess = 0.0f);
    virtual ~BattleObjBase() = default;
    
    static BattleObjBase* create(int hp, int att, float vel, std::string cha, float velProcess = 0.0f);
    
    
    void setHP(int hp);
    int getHP();
    
    void setAttack(int attack);
    int getAttack();
    
    void setVelocity(float vel);
    float getVelocity();
    
    void setVelPro(float vel);
    float getVelPro();

    
    virtual void update(float dt, const BattleObjCallback& callback);

    bool init(std::string cha);
    
private:
    int p_HP;
    int p_ATTACK;
    float p_VELOCITY;
    float p_velcity_process;
};

#endif /* BattleObjBase_hpp */
