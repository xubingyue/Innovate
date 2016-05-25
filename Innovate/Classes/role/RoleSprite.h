//
//  RoleSprite.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/15.
//
//

#ifndef RoleSprite_hpp
#define RoleSprite_hpp

#include "MapObjBase.h"

using namespace cocos2d;

class RoleSprite : public MapObjBase
{
public:
    static RoleSprite* create(std::string str);
    
    void resetZorder(Point p) override;
};

#endif /* RoleSprite_hpp */
