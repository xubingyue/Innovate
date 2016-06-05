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
#include "../model/BagModel.h"
#include "../utils/IconUtil.h"

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
    p_root = CSLoader::createNodeWithVisibleSize("res/ui/BagView/BagView.csb");
    addChild(p_root);
    
    p_scrollView = static_cast<ScrollView*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "bag_scroll_view"));
    
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

void BagView::open(int index)
{
    vector<BagItemWithCount*> *itemList;
    if (index == 0) //元素背包
    {
        itemList = BagModel::getInstance()->eleItemList;
    }
    
    int jiange = 74;    //图标直接的固定间隔
    int x = 10;
    int y = p_scrollView->getContentSize().height - jiange;
    
    for (int i = 0; i < itemList->size(); i++)
    {
        auto icon = IconUtil::getInstance()->getIconById(IconType::IconType_ELEMENT, (*itemList)[i]->item->itemId, (*itemList)[i]->count);
//        icon->addTouchEventListener();
//        >addTouchEventListener(CC_CALLBACK_2(BattleResultView::touchEventCallback, this));
        p_scrollView->addChild(icon);
        icon->setPosition(x, y);
        x += jiange;
        if (i !=0 && (i % 6) == 0)
        {
            y -= jiange;
        }
    }
}

void BagView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        this->removeFromParentAndCleanup(true);
    }
}
