//
//  RoleSprite.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/15.
//
//

#include "RoleSprite.h"

RoleSprite* RoleSprite::create(std::string map)
{
    RoleSprite * ret = new (std::nothrow) RoleSprite();
    if (ret && ret->initWithFile(map))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

void RoleSprite::resetZorder(Point p)
{
    this->setLocalZOrder(p.y * 1000 + p.x * 100 + 1);
}


