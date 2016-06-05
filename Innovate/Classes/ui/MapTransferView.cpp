//
//  MapTransferView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/4.
//
//

#include "MapTransferView.h"
#include "cocostudio/CocoStudio.h"
#include "DataManager.h"
#include "StringUtil.h"
#include "LocalDataManager.h"

USING_NS_CC;
using namespace cocos2d::ui;

MapTransferView* MapTransferView::create(int currMapId)
{
    MapTransferView * ret = new (std::nothrow) MapTransferView();
    if (ret && ret->init(currMapId))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

MapTransferView::MapTransferView()
{
    
}

MapTransferView::~MapTransferView()
{
    
}

bool MapTransferView::init(int currMapId)
{
    auto root = CSLoader::createNodeWithVisibleSize("res/ui/MainView/TransferView.csb");
    this->addChild(root);
    
    Button *backBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(root), "back_btn"));
    backBtn->addTouchEventListener(CC_CALLBACK_2(MapTransferView::backEventCallback, this));
    
    ListView *listView = static_cast<ListView*>(Helper::seekWidgetByName(static_cast<Layout*>(root), "list_view"));

    int farthest = LocalDataManager::getInstance()->getFarthestMap();
    //下一关卡是否开放
    bool isOpenNew = false;
    
    
    for (int i = 1; i <= farthest + 1; i++)
    {
        if (i != currMapId)
        {
            auto vo = SCENE_MAP_TABLE->getScene_mapVo(i);
            Text *txt = Text::create(StringUtil::intToString(i) + ":" + vo->map_name, "", 36);
            txt->setName(StringUtil::intToString(i));
            txt->setTouchEnabled(true);
            txt->addTouchEventListener(CC_CALLBACK_2(MapTransferView::touchEventCallback, this));
            listView->addChild(txt);
            
            if (i == farthest + 1 && !isOpenNew)
            {
                txt->setColor(Color3B::BLUE);
                txt->setName("no");
            }
        }
    }
    
    return true;
}

void MapTransferView::backEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        this->removeFromParentAndCleanup(true);
    }
}

void MapTransferView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        auto txt = static_cast<Text*>(sender);
        CCLOG("======%s", txt->getName().c_str());
        if (txt->getName() == "no")
        {
            //新地图未解锁
        } else {
            //goto new map
        }
    }
}




