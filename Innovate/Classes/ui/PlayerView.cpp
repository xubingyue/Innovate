//
//  PlayerView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#include "PlayerView.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocos2d::ui;


PlayerView* PlayerView::create()
{
    PlayerView * ret = new (std::nothrow) PlayerView();
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

PlayerView::PlayerView()
{
    
}

PlayerView::~PlayerView()
{
    
}

bool PlayerView::init()
{

    p_root = CSLoader::createNodeWithVisibleSize("res/ui/PlayerView/PlayerView.csb");
    addChild(p_root);
    
    Button *backBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "back_btn"));
    backBtn->addTouchEventListener(CC_CALLBACK_2(PlayerView::touchEventCallback, this));

    

    return true;
}

void PlayerView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        this->removeFromParentAndCleanup(true);
    }
}






