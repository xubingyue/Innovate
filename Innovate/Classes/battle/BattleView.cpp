//
//  BattleView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/19.
//
//

#include "BattleView.h"
#include "cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/CCComExtensionData.h"
#include "../UICommon.h"



USING_NS_CC;
using namespace cocos2d::ui;

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
    
    //加载ui
//    Data data = FileUtils::getInstance()->getDataFromFile("res/ui/BattleView/BattleView.csb");
    Node* node = CSLoader::createNodeWithVisibleSize("res/ui/BattleView/BattleView.csb");
//    cocostudio::timeline::ActionTimeline* action = CSLoader::createTimeline(data, "ActionTimeline/DemoPlayer.csb");
//    node->runAction(action);
//    action->gotoFrameAndPlay(0);
//    node->setContentSize(winSize);
//    ui::Helper::doLayout(node);
    addChild(node);
    
    Button *escapeBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(node), "escape_btn"));
//    Button *escapeBtn = HELPER_GET_BTN(node, "escape_btn");
    escapeBtn->addTouchEventListener(CC_CALLBACK_2(BattleView::touchEventCallback, this));

    return true;
}

void BattleView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
//        _editBoxImpl->openKeyboard();
        CCLOG("------->>>>");
        this->removeFromParentAndCleanup(true);
    }
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

