//
//  BigCrystalView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#include "BigCrystalView.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocos2d::ui;


BigCrystalView* BigCrystalView::create()
{
    BigCrystalView * ret = new (std::nothrow) BigCrystalView();
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

BigCrystalView::BigCrystalView()
{
    
}

BigCrystalView::~BigCrystalView()
{
    
}

bool BigCrystalView::init()
{
    
    p_root = CSLoader::createNodeWithVisibleSize("res/ui/BigCrystalView/BigCrystalView.csb");
    addChild(p_root);
    
    Button *backBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "back_btn"));
    backBtn->addTouchEventListener(CC_CALLBACK_2(BigCrystalView::touchEventCallback, this));
    
    return true;
}

void BigCrystalView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        this->removeFromParent();
    }
}