//
//  UIComponent.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#include "UIComponent.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocos2d::ui;


static UIComponent* _instance;

UIComponent* UIComponent::getInstance(Node *layer)
{
    if (_instance == nullptr)
    {
        _instance = new (std::nothrow) UIComponent();
        if (_instance && _instance->init(layer))
        {
            _instance->autorelease();
        }
        else
        {
            CC_SAFE_DELETE(_instance);
        }
    }
    return _instance;
}

bool UIComponent::init(Node *layer)
{
    if (!Layer::init())
    {
        return false;
    }
    
    p_root = CSLoader::createNodeWithVisibleSize("res/ui/MainView/MainView.csb");
    addChild(p_root);
    //添加到主ui
    layer->addChild(this);
    
    Button *mapBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "map_btn"));
    mapBtn->addTouchEventListener(CC_CALLBACK_2(UIComponent::touchEventCallback, this));
    
    Node *bottomNode = p_root->getChildByName("bottom_node");
    
    Button *playerBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(bottomNode), "player_btn"));
    playerBtn->addTouchEventListener(CC_CALLBACK_2(UIComponent::touchEventCallback, this));
    
    Button *elfBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(bottomNode), "elf_btn"));
    elfBtn->addTouchEventListener(CC_CALLBACK_2(UIComponent::touchEventCallback, this));
    
    Button *crystalBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(bottomNode), "crystal_btn"));
    crystalBtn->addTouchEventListener(CC_CALLBACK_2(UIComponent::touchEventCallback, this));
    
    return  true;
}

void UIComponent::touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        auto btn = static_cast<Button*>(sender);
        if (btn->getName() == "map_btn")
        {
            CCLOG("map_btn");
        } else if (btn->getName() == "player_btn")
        {
            CCLOG("player_btn");
        } else if (btn->getName() == "elf_btn")
        {
            CCLOG("elf_btn");
        } else if (btn->getName() == "crystal_btn")
        {
            CCLOG("crystal_btn");
        }
    }
}






