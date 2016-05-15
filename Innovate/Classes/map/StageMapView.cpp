//
//  StageMapView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/14.
//
//

#include "StageMapView.h"

StageMapView* StageMapView::create(std::string map)
{
    StageMapView * ret = new (std::nothrow) StageMapView();
    if (ret && ret->init(map))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool StageMapView::init(std::string str)
{
    tmxMap = TMXTiledMap::create(str);
    this->addChild(tmxMap);
    return true;
}

TMXTiledMap* StageMapView::getMap()
{
    return tmxMap;
}

// OpenGL坐标转成格子坐标
Vec2 StageMapView::tileCoordForPosition(const Vec2& position)
{
    Size mapSize = tmxMap->getMapSize();
    Size tileSize = tmxMap->getTileSize();
    int x = position.x / tileSize.width;
    int y = (mapSize.height*tileSize.height - position.y) / tileSize.height;
    return Vec2(x, y);
}
// tile坐标转成瓦片格子中心的OpenGL坐标
Vec2 StageMapView::positionForTileCoord(const Vec2& tileCoord)
{
    Size mapSize = tmxMap->getMapSize();
    Size tileSize = tmxMap->getTileSize();
    int x = tileCoord.x * tileSize.width + tileSize.width/2;
    int y = (mapSize.height-tileCoord.y)*tileSize.height - tileSize.height/2;
    return Vec2(x, y);
}