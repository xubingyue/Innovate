//
//  BagView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/2.
//
//

#include "BagView.h"
#include "cocostudio/CocoStudio.h"
#include "UIComponent.h"
#include "GlobalModel.h"
#include "DataManager.h"

USING_NS_CC;
using namespace cocos2d::ui;


BagView* BagView::create()
{
    BagView * ret = new (std::nothrow) BagView();
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

BagView::BagView()
{
    
}

BagView::~BagView()
{
    
}

bool BagView::init()
{
//    auto vo = CONFIG_TABLE->getConfigVo(2);
//    GlobalModel::getInstance()->MoveSteps = StringUtil::stringToInt(vo->data);
//    UIComponent::getInstance()->updateLimit(GlobalModel::getInstance()->MoveSteps);
    
    p_root = CSLoader::createNodeWithVisibleSize("res/ui/BagView/BagView.csb");
    addChild(p_root);
    
    p_scrollView = static_cast<ScrollView*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "bag_scroll_view"));
//    backBtn->addTouchEventListener(CC_CALLBACK_2(BigCrystalView::touchEventCallback, this));
    
    p_btnNode = p_root->getChildByName("btn_node");
    
    return true;
}

void BagView::setContentSize(cocos2d::Size s)
{
    float tempH = s.height - p_scrollView->getContentSize().height;
    p_btnNode->setPositionY(p_btnNode->getPositionY() + tempH);
    p_scrollView->setContentSize(s);
    p_scrollView->setInnerContainerSize(s);
}

void BagView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        this->removeFromParentAndCleanup(true);
    }
}
