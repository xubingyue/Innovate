//
//  LoadingScene.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/13.
//
//

#include "LoadingScene.h"
#include "DataManager.h"
#include "HelloWorldScene.h"
#include "model/PlayerModel.h"
#include "LocalDataManager.h"
#include "BagModel.h"
#include "LanguageUtil.h"


USING_NS_CC;

Scene* LoadingScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LoadingScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LoadingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = Label::createWithTTF("Loading...", "fonts/Marker Felt.ttf", 34);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    //load数据
    DataManager::getInstance()->loadTable(nullptr, "staticdata");
    
    //初始化人物数据
    LocalDataManager::getInstance()->init("AA");
    auto player = ROLE_TABLE->getRoleVo(1);
    if(!LocalDataManager::getInstance()->getFirstOpen())
    {
        PlayerModel::getInstance()->init(1, player->hp, player->attack, player->velocity,
                                         player->darkAttack, player->darkResist, player->fireAttack,
                                         player->fireResist, player->windAttack, player->windResist, player->ski1,
                                         player->soilAttack, player->soilResist, player->recover, player->absorb);
        LocalDataManager::getInstance()->setPlayerLv(1);
        LocalDataManager::getInstance()->setFarthestMap(1);
        LocalDataManager::getInstance()->setFirstOpen(true);
        LocalDataManager::getInstance()->setCurrFubenId(-1);
    } else {
        int level = LocalDataManager::getInstance()->getPlayerLv();
        PlayerModel::getInstance()->init(level, player->hp, player->attack, player->velocity,
                                         player->darkAttack, player->darkResist, player->fireAttack,
                                         player->fireResist, player->windAttack, player->windResist, player->ski1,
                                         player->soilAttack, player->soilResist, player->recover, player->absorb);
    }
    
    //加载常驻内存资源
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/common/common_icon.plist", "res/common/common_icon.pvr.ccz");
    
    //加载背包数据
    auto eleItems = LocalDataManager::getInstance()->getEleBagItems();
    if (eleItems != "")
    {
        BagModel::getInstance()->initData(eleItems);
    }
    
    //初始化语言
    LanguageUtil::initLanguage(LanguageType::CHINESE);
    
    //------test---------
    
    
   
    //---------------------------------------------
    this->schedule(schedule_selector(LoadingScene::runOnce), 1, 1, 0);
    return true;
}

void LoadingScene::runOnce(float dt)
{
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(scene);
}