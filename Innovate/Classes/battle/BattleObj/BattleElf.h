//
//  BattleElf.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/23.
//
//

#ifndef BattleElf_hpp
#define BattleElf_hpp

#include "BattleObjBase.h"


class BattleElf : public BattleObjBase
{
public:
    static BattleElf* create(int hp, int att, float vel, std::string cha,float velProcess = 0.0f);
    
    BattleElf();
    BattleElf(int hp, int att, float vel, float velProcess = 0.0f);
    ~BattleElf();
 
    void update(float dt, const BattleObjCallback& callback) override;
};

#endif /* BattleElf_hpp */
