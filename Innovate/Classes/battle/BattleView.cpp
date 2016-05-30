//
//  BattleView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/19.
//
//

#include "BattleView.h"
#include "cocostudio/CocoStudio.h"
//#include "editor-support/cocostudio/CCComExtensionData.h"
#include "../UICommon.h"
#include "BattleController.h"
#include "../ui/UIComponent.h"


USING_NS_CC;
using namespace cocos2d::ui;

BattleView* BattleView::create(string mapId, Vec2 point)
{
    BattleView * ret = new (std::nothrow) BattleView();
    if (ret && ret->init(mapId, point))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

BattleView::BattleView()
:p_isExit(false)
{
    
}

BattleView::~BattleView()
{
    
}

bool BattleView::init(string mapId, Vec2 point)
{
    if (!Layer::init())
    {
        return false;
    }
    //隐藏主ui
    UIComponent::getInstance()->showVisiable(false);
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
    p_root = CSLoader::createNodeWithVisibleSize("res/ui/BattleView/BattleView.csb");
    addChild(p_root);
    
    Button *escapeBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "escape_btn"));
    escapeBtn->addTouchEventListener(CC_CALLBACK_2(BattleView::touchEventCallback, this));

    p_monsterNode = p_root->getChildByName("monster_node");
    p_playerNode = p_root->getChildByName("player_node");
    
    effectNode_1 = p_root->getChildByName("effect_node_1");
    effectNode_2 = p_root->getChildByName("effect_node_2");
    
    return true;
}

void BattleView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        this->unschedule(CC_SCHEDULE_SELECTOR(BattleView::updateTimer));
        p_isExit = true;
        CCLOG("------->>>>退出战斗！");
        BattleController::getInstance()->exitBattle();
    }
}

void BattleView::addPlayer(BattleObjBase *obj)
{
    p_playerNode->addChild(obj);
}

void BattleView::addElfs(Vector<BattleElf*> *elfs)
{
    int i = 1;
    for (BattleObjBase *elf : *elfs)
    {
        char buffer[100];
        sprintf(buffer,"elf_node_%d",i);
        string temp(buffer);
        auto node = p_root->getChildByName(temp);
        if (node != nullptr)
        {
            node->addChild(elf);
            i++;
            continue;
        }
        break;
    }
}

void BattleView::addMonster(BattleObjBase *monster)
{
    p_monsterNode->addChild(monster);
}

void BattleView::updateTimer(float dt)
{
    if (p_isExit) return;
    //战斗时间轴
    BattleController::getInstance()->updateTimer(dt);
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
    UIComponent::getInstance()->showVisiable(true);
    this->unschedule(CC_SCHEDULE_SELECTOR(BattleView::updateTimer));
}

