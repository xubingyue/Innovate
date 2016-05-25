//
//  MapObjBase.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/25.
//
//

#include "MapObjBase.h"

void MapObjBase::resetZorder(Point p)
{
    this->setLocalZOrder(p.y * 1000 + p.x * 100);
}