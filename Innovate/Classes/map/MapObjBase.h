//
//  MapObjBase.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/25.
//
//

#ifndef MapObjBase_hpp
#define MapObjBase_hpp

#include "cocos2d.h"
#include "StageMapView.h"

USING_NS_CC;

class MapObjBase : public Sprite
{
public:
    virtual void resetZorder(Point p);

public:
    //当前所在地图上的坐标
    Point corrd;
    //当前对象id
    int buildId;
    
};

#endif /* MapObjBase_hpp */
