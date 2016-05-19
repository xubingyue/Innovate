//
//  BattleView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/19.
//
//

#include "BattleView.h"

USING_NS_CC;

BattleView* BattleView::create()
{
    BattleView * ret = new (std::nothrow) BattleView();
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool BattleView::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    auto winSize = Director::getInstance()->getWinSize();
    
    auto bg = Sprite::create("res/battleBg/map_1_1.pvr.ccz");
    bg->setPosition(Point(winSize.width/2, winSize.height/2));
    this->addChild(bg);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(BattleView::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(BattleView::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(BattleView::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

bool BattleView::onTouchBegan(Touch *touch, Event *unused_event)
{
    return true;
}
void BattleView::onTouchMoved(Touch *touch, Event *unused_event)
{
    
}
void BattleView::onTouchEnded(Touch *touch, Event *unused_event)
{
    
}

void BattleView::onEnter()
{
    Layer::onEnter();
    setTouchEnabled(true);
    setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    setSwallowsTouches(true);
}

void BattleView::onExit()
{
    Layer::onExit();
    
}

