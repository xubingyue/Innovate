//
//  MapObjBuilding.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/25.
//
//

#include "MapObjBuilding.h"

MapObjBuilding* MapObjBuilding::create(std::string str)
{
    MapObjBuilding * ret = new (std::nothrow) MapObjBuilding();
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