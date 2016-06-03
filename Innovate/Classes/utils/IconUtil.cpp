//
//  IconUtil.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/3.
//
//

#include "IconUtil.h"
#include "DataManager.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "StringUtil.h"

USING_NS_CC;
using namespace cocos2d::ui;

static IconUtil* _instance = nullptr;

IconUtil* IconUtil::getInstance()
{
    if (_instance == nullptr) {
        _instance = new IconUtil();
    }
    return _instance;
}

Node* IconUtil::getIconById(IconType type, int id, int count)
{
    auto node = CSLoader::createNodeWithVisibleSize("res/ui/BattleView/DropItem.csb");
    auto bg = static_cast<Layout*>(Helper::seekWidgetByName(static_cast<Layout*>(node), "bg_node"));
    Text *txt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(node), "count_txt"));
    switch (type) {
        case IconType::IconType_ELEMENT:
        {
            auto vo = ELEMENT_TABLE->getElementVo(id);
            Sprite *icon = Sprite::createWithSpriteFrameName(vo->icon);
            icon->setAnchorPoint(Point(0, 0));
            bg->addChild(icon);
            txt->setString("x" + StringUtil::intToString(count));
            break;
        }
        default:
        {
            return node;
        }
    }
    return node;
}