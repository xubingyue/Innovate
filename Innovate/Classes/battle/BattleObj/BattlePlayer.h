//
//  BattlePlayer.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/23.
//
//

#ifndef BattlePlayer_hpp
#define BattlePlayer_hpp

#include "BattleObjBase.h"


class BattlePlayer : public BattleObjBase
{
public:
    static BattlePlayer* create(int hp, int att, float vel, std::string cha,float velProcess = 0.0f);
    
    BattlePlayer();
    BattlePlayer(int hp, int att, float vel, float velProcess = 0.0f);
    ~BattlePlayer();

    void update(float dt, const BattleObjCallback& callback) override;
    void showEffect();
private:
    void showEffectOver();
};


#endif /* BattlePlayer_hpp */
