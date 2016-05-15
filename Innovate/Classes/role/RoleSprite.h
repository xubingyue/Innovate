//
//  RoleSprite.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/15.
//
//

#ifndef RoleSprite_hpp
#define RoleSprite_hpp

#include "cocos2d.h"
using namespace cocos2d;

class RoleSprite : public Sprite
{
public:
    static RoleSprite* create(std::string str);
};

#endif /* RoleSprite_hpp */
