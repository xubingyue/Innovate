//
//  MonsterModel.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/25.
//
//

#ifndef MonsterModel_hpp
#define MonsterModel_hpp

#include "ModelBase.h"

using namespace std;

class MonsterModel : public ModelBase
{
public:
    MonsterModel();
    ~MonsterModel();
    
    void setName(string name);
    string getName();
    
    void setHp(int hp);
    int getHp();
    
    void setAttack(int atk);
    int getAttack();
    
    void setVelocity(float velocity);
    float getVelocity();
    
    void setVeloBuff(float vb);
    float getVeloBuff();
    
public:
    string res;
private:
    string name;
    int hp;
    int attack;
    float velocity;
    float velo_buff;
};


#endif /* MonsterModel_hpp */
