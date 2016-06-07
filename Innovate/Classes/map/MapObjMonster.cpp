//
//  MapObjMonster.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/7.
//
//

#include "MapObjMonster.h"

MapObjMonster* MapObjMonster::create(std::string str)
{
    MapObjMonster * ret = new (std::nothrow) MapObjMonster();
    if (ret && ret->initWithFile(str))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}