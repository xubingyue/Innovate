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
#include "../model/GlobalModel.h"
#include "../core/data/DataManager.h"
#include "../model/BagModel.h"
#include "../utils/IconUtil.h"
#include "../NotificationType.h"

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
    
    p_btn_1 = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_btnNode), "btn_1"));
    p_btn_1->addTouchEventListener(CC_CALLBACK_2(BagView::shiftBagEvent, this));
    
    p_btn_2 = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_btnNode), "btn_2"));
    p_btn_2->addTouchEventListener(CC_CALLBACK_2(BagView::shiftBagEvent, this));
    
    p_btn_3 = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_btnNode), "btn_3"));
    p_btn_3->addTouchEventListener(CC_CALLBACK_2(BagView::shiftBagEvent, this));
    
    p_btn_4 = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_btnNode), "btn_4"));
    p_btn_4->addTouchEventListener(CC_CALLBACK_2(BagView::shiftBagEvent, this));
    
    p_btn_5 = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_btnNode), "btn_5"));
    p_btn_5->addTouchEventListener(CC_CALLBACK_2(BagView::shiftBagEvent, this));
    
    return true;
}

void BagView::setContentSize(cocos2d::Size s)
{
    float tempH = s.height - p_scrollView->getContentSize().height;
    p_btnNode->setPositionY(p_btnNode->getPositionY() + tempH);
    p_scrollView->setContentSize(s);
    p_scrollView->setInnerContainerSize(s);
}

void BagView::open(BagType index, bool isShowBtn)
{
    p_btnNode->setVisible(isShowBtn);
    p_scrollView->removeAllChildrenWithCleanup(true);
    vector<BagItemWithCount*> *itemList;
    if (index == BagType::BagType_ELEMENT) //元素背包
    {
        itemList = BagModel::getInstance()->eleItemList;
    }
    
    if (itemList == nullptr) return;
    
    int jiange = 74;    //图标直接的固定间隔
    int x = 10;
    int y = p_scrollView->getContentSize().height - jiange;
    
    for (int i = 0; i < itemList->size(); i++)
    {
        auto icon = IconUtil::getInstance()->getIconById(IconType::IconType_ELEMENT, (*itemList)[i]->item->itemId, (*itemList)[i]->count);
        p_scrollView->addChild(icon);
        icon->setPosition(x, y);
        x += jiange;
        if (i !=0 && (i % 6) == 0)
        {
            y -= jiange;
        }
    }
}

void BagView::open(BagType index, int itemId1, int itemId2, bool isShowBtn)
{
    p_btnNode->setVisible(isShowBtn);
    p_scrollView->removeAllChildrenWithCleanup(true);
    vector<BagItemWithCount*> *itemList;
    if (index == BagType::BagType_ELEMENT) //元素背包
    {
        itemList = BagModel::getInstance()->eleItemList;
    }
    
    if (itemList == nullptr) return;
    
    int jiange = 74;    //图标直接的固定间隔
    int x = 10;
    int y = p_scrollView->getContentSize().height - jiange;
    
    int i = 0;
    while (i < itemList->size())
    {
        auto vo = (*itemList)[i];
        int tempCount = vo->count;

        if (vo->item->itemId == itemId1 || vo->item->itemId == itemId1)
        {
            tempCount--;
        }
        if (tempCount <= 0) continue;
        auto icon = IconUtil::getInstance()->getIconById(IconType::IconType_ELEMENT, vo->item->itemId, tempCount);
        
        // Register Touch Event
        Layout *bgNode = static_cast<Layout*>(Helper::seekWidgetByName(static_cast<Layout*>(icon), "bg_node"));
        bgNode->setTag(vo->item->itemId);
        bgNode->addTouchEventListener(CC_CALLBACK_2(BagView::onTouchEnded, this));
        
        p_scrollView->addChild(icon);
        icon->setPosition(x, y);
        x += jiange;
        if (i !=0 && (i % 6) == 0)
        {
            y -= jiange;
        }
        i++;
    }
}

void BagView::shiftBagEvent(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        auto btn = static_cast<Button*>(sender);
        if (btn->getName() == "btn_1")
        {
            open(BagType::BagType_ELEMENT);
            p_btn_1->setEnabled(false);
            p_btn_2->setEnabled(true);
            p_btn_3->setEnabled(true);
            p_btn_4->setEnabled(true);
            p_btn_5->setEnabled(true);
        } else if (btn->getName() == "btn_2")
        {
            open(BagType::BagType_ELEMENT);
            p_btn_1->setEnabled(true);
            p_btn_2->setEnabled(false);
            p_btn_3->setEnabled(true);
            p_btn_4->setEnabled(true);
            p_btn_5->setEnabled(true);
        } else if (btn->getName() == "btn_3")
        {
            open(BagType::BagType_ELEMENT);
            p_btn_1->setEnabled(true);
            p_btn_2->setEnabled(true);
            p_btn_3->setEnabled(false);
            p_btn_4->setEnabled(true);
            p_btn_5->setEnabled(true);
        } else if (btn->getName() == "btn_4")
        {
            open(BagType::BagType_ELEMENT);
            p_btn_1->setEnabled(true);
            p_btn_2->setEnabled(true);
            p_btn_3->setEnabled(true);
            p_btn_4->setEnabled(false);
            p_btn_5->setEnabled(true);
        } else if (btn->getName() == "btn_5")
        {
            open(BagType::BagType_ELEMENT);
            p_btn_1->setEnabled(true);
            p_btn_2->setEnabled(true);
            p_btn_3->setEnabled(true);
            p_btn_4->setEnabled(true);
            p_btn_5->setEnabled(false);
        } else {
            open(BagType::BagType_ELEMENT);
            p_btn_1->setEnabled(false);
            p_btn_2->setEnabled(true);
            p_btn_3->setEnabled(true);
            p_btn_4->setEnabled(true);
            p_btn_5->setEnabled(true);
        }
    }
}

void BagView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        this->removeFromParentAndCleanup(true);
    }
}

void BagView::onTouchEnded(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        Layout *bgNode = static_cast<Layout*>(sender);
        NotifiyRef *obj = new NotifiyRef();
        obj->nid = bgNode->getTag();
        __NotificationCenter::getInstance()->postNotification(CLICK_BAG_ELEMENT, obj);
    }
}
