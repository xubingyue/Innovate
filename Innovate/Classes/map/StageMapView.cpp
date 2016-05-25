//
//  StageMapView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/14.
//
//

#include "StageMapView.h"
#include "../NotificationType.h"

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
    p_tmxMap = TMXTiledMap::create(str);
    this->addChild(p_tmxMap, 0);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(StageMapView::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(StageMapView::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(StageMapView::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    
    return true;
}

TMXTiledMap* StageMapView::getMap()
{
    return p_tmxMap;
}

// OpenGL坐标转成格子坐标
Vec2 StageMapView::tileCoordForPosition(const Vec2& position)
{
    Size mapSize = p_tmxMap->getMapSize();
    Size tileSize = p_tmxMap->getTileSize();
    int x = position.x / tileSize.width;
    int y = (mapSize.height*tileSize.height - position.y) / tileSize.height;
    return Vec2(x, y);
}
// tile坐标转成瓦片格子中心的OpenGL坐标
Vec2 StageMapView::positionForTileCoord(const Vec2& tileCoord)
{
    Size mapSize = p_tmxMap->getMapSize();
    Size tileSize = p_tmxMap->getTileSize();
    int x = tileCoord.x * tileSize.width + tileSize.width/2;
    int y = (mapSize.height-tileCoord.y)*tileSize.height - tileSize.height/2;
    return Vec2(x, y);
}

void StageMapView::addToMap(Node *child, Point p)
{
    this->addChild(child, p.y * 1000 + p.x * 100);
}

bool StageMapView::onTouchBegan(Touch *touch, Event *unused_event)
{
    
    return true;
}

void StageMapView::onTouchMoved(Touch *touch, Event *unused_event)
{
}

void StageMapView::onTouchEnded(Touch *touch, Event *unused_event)
{
    
    Point p = touch->getLocation();
    auto currPoint = this->convertToNodeSpace(p);
//    Vec2 v = tileCoordForPosition(currPoint);
//    auto layer = getMap()->getLayer("Road");
//    auto sp = layer->getTileAt(v);
//    if (sp)
//    {
    __NotificationCenter::getInstance()->postNotification(TOUCH_MAP_TO_MOVE, touch);
//    }
}
