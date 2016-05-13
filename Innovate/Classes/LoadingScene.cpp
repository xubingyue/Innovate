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
    
    DataManager::getInstance()->loadTable(nullptr, "staticdata");
    
    this->schedule(schedule_selector(LoadingScene::runOnce), 1, 1, 0);
    return true;
}

void LoadingScene::runOnce(float dt)
{
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(scene);
}