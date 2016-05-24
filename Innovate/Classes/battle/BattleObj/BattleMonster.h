//
//  BattleMonster.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/23.
//
//

#ifndef BattleMonster_hpp
#define BattleMonster_hpp

#include "BattleObjBase.h"


class BattleMonster : public BattleObjBase
{
public:
    static BattleMonster* create(int hp, int att, float vel, std::string cha,float velProcess = 0.0f);
    
    BattleMonster();
    BattleMonster(int hp, int att, float vel, float velProcess = 0.0f);
    ~BattleMonster();
    
    void update(float dt, const BattleObjCallback& callback) override;
};

#endif /* BattleMonster_hpp */
