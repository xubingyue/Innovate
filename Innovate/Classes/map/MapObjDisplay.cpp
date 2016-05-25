//
//  MapObjDisplay.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/25.
//
//

#include "MapObjDisplay.h"

MapObjDisplay* MapObjDisplay::create(std::string str)
{
    MapObjDisplay * ret = new (std::nothrow) MapObjDisplay();
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