//
//  BigCrystalView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#include "BigCrystalView.h"
#include "cocostudio/CocoStudio.h"
#include "UIComponent.h"
#include "../model/GlobalModel.h"
#include "../core/data/DataManager.h"
#include "../core/utils/StringUtil.h"
#include "BagView.h"
#include "../NotificationType.h"

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
    p_selectedId1 = 0;
    p_selectedId2 = 0;
}

BigCrystalView::~BigCrystalView()
{
    
}

bool BigCrystalView::init()
{
    //注册背包消息返回
    __NotificationCenter::getInstance()->addObserver(this,
                                                     CC_CALLFUNCO_SELECTOR(BigCrystalView::touchBagEle),
                                                     CLICK_BAG_ELEMENT,
                                                     nullptr);
    
    auto vo = CONFIG_TABLE->getConfigVo(2);
    GlobalModel::getInstance()->MoveSteps = StringUtil::stringToInt(vo->data);
    UIComponent::getInstance()->updateLimit(GlobalModel::getInstance()->MoveSteps);
    
    p_root = CSLoader::createNodeWithVisibleSize("res/ui/BigCrystalView/BigCrystalView.csb");
    addChild(p_root);
    //返回按钮
    Button *backBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "back_btn"));
    backBtn->addTouchEventListener(CC_CALLBACK_2(BigCrystalView::touchEventCallback, this));
    
    //view node
    p_viewNode = p_root->getChildByName("view_node");
    
    //切换分页
    Button *findBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "find_btn"));
    findBtn->addTouchEventListener(CC_CALLBACK_2(BigCrystalView::shiftPageCallback, this));
    
    Button *synthesisBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "synthesis_btn"));
    synthesisBtn->addTouchEventListener(CC_CALLBACK_2(BigCrystalView::shiftPageCallback, this));
    
    Button *enchantBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "enchant_btn"));
    enchantBtn->addTouchEventListener(CC_CALLBACK_2(BigCrystalView::shiftPageCallback, this));
    
    Button *produceBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "produce_btn"));
    produceBtn->addTouchEventListener(CC_CALLBACK_2(BigCrystalView::shiftPageCallback, this));
    
    //合成按钮
    Button *goBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "go_btn"));
    goBtn->addTouchEventListener(CC_CALLBACK_2(BigCrystalView::touchEventCallback, this));

    //合成元素1
    ImageView *ele_1_bg = static_cast<ImageView*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "ele_1_bg"));
    Button *ele_1_btn = static_cast<Button*>(Helper::seekWidgetByName(ele_1_bg, "ele_1_btn"));
    ele_1_btn->addTouchEventListener(CC_CALLBACK_2(BigCrystalView::touchEventCallback, this));
    
    //合成元素2
    ImageView *ele_2_bg = static_cast<ImageView*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "ele_2_bg"));
    Button *ele_2_btn = static_cast<Button*>(Helper::seekWidgetByName(ele_2_bg, "ele_2_btn"));
    ele_2_btn->addTouchEventListener(CC_CALLBACK_2(BigCrystalView::touchEventCallback, this));
    //二级背包节点
    p_bagNode = p_root->getChildByName("bag_node");
    return true;
}

void BigCrystalView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        Button *btn = static_cast<Button*>(sender);
        if (btn->getName() == "back_btn")
        {
            this->removeFromParentAndCleanup(true);
        } else if (btn->getName() == "go_btn")
        {
            CCLOG("go_btn");
        } else if (btn->getName() == "ele_1_btn")
        {
            p_selectedBtn = 1;
            BagView *bv = BagView::create();
            bv->setContentSize(Size(580, 480));
            bv->open(BagType::BagType_ELEMENT, p_selectedId1, p_selectedId2, false);
            p_bagNode->addChild(bv);
        } else if (btn->getName() == "ele_2_btn")
        {
            p_selectedBtn = 2;
            BagView *bv = BagView::create();
            bv->setContentSize(Size(580, 480));
            bv->open(BagType::BagType_ELEMENT, p_selectedId1, p_selectedId2, false);
            p_bagNode->addChild(bv);
        }
    }
}

void BigCrystalView::shiftPageCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        Button *btn = static_cast<Button*>(sender);
        if (btn->getName() == "find_btn")
        {
            p_viewNode->removeAllChildrenWithCleanup(true);
        } else if (btn->getName() == "synthesis_btn")
        {
            p_viewNode->removeAllChildrenWithCleanup(true);
            auto synthesisView = SynthesisView::create();
            p_viewNode->addChild(synthesisView);
        } else if (btn->getName() == "enchant_btn")
        {
            p_viewNode->removeAllChildrenWithCleanup(true);
            auto enchantView = EnchantView::create();
            p_viewNode->addChild(enchantView);
        } else if (btn->getName() == "produce_btn")
        {
            p_viewNode->removeAllChildrenWithCleanup(true);
            auto produceView = ProduceView::create();
            p_viewNode->addChild(produceView);
        }
    }
}

void BigCrystalView::touchBagEle(Ref *obj)
{
    auto o = static_cast<NotifiyRef*>(obj);
    if (p_selectedBtn == 1)
    {
        p_selectedId1 = o->nid;
    } else {
        p_selectedId2 = o->nid;
    }
    delete obj;
}


#pragma mark ------------------元素合成界面--------------------
SynthesisView* SynthesisView::create()
{
    SynthesisView * ret = new (std::nothrow) SynthesisView();
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

SynthesisView::SynthesisView()
{
    
}

SynthesisView::~SynthesisView()
{
    
}

bool SynthesisView::init()
{
    p_root = CSLoader::createNodeWithVisibleSize("res/ui/BigCrystalView/SynthesisView.csb");
    addChild(p_root);
    return true;
}


#pragma mark ---------------------装备附魔界面---------------------
EnchantView* EnchantView::create()
{
    EnchantView * ret = new (std::nothrow) EnchantView();
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

EnchantView::EnchantView()
{
    
}

EnchantView::~EnchantView()
{
    
}

bool EnchantView::init()
{
    p_root = CSLoader::createNodeWithVisibleSize("res/ui/BigCrystalView/EnchantView.csb");
    addChild(p_root);
    return true;
}

#pragma mark ---------------------元素生产界面---------------------
ProduceView* ProduceView::create()
{
    ProduceView * ret = new (std::nothrow) ProduceView();
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

ProduceView::ProduceView()
{
    
}

ProduceView::~ProduceView()
{
    
}

bool ProduceView::init()
{
    p_root = CSLoader::createNodeWithVisibleSize("res/ui/BigCrystalView/ProduceVIew.csb");
    addChild(p_root);
    return true;
}








