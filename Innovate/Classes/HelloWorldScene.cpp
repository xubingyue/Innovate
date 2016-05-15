#include "HelloWorldScene.h"
#include "DataManager.h"
#include "MemManager.h"
#include "LayerManager.h"
#include "NotificationType.h"

USING_NS_CC;
using namespace std;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

    //初始化层级
    LayerManager::getInstance()->initLayer(this);

    //初始化世界地图
    initWorldMap();

    
    
//    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
//    
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);
//
//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("res/HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
//    auto role = ROLE_TABLE->getRoleVo(1);
//    
//    CCLOG("====>%s", role->name.c_str());
//    
//    int temp = 99;
//    
//    m_int sto = MemManager::getInstance()->encode(temp);
//    
//    CCLOG("%d ===== %s", sto.value, sto.md5.c_str());
//    
//    int result = MemManager::getInstance()->decode(sto);
//    
//    CCLOG("====>>>>>%d", result);
    __NotificationCenter::getInstance()->addObserver(this, CC_CALLFUNCO_SELECTOR
                                                     (HelloWorld::touch2Move),
                                                     TOUCH_MAP_TO_MOVE, nullptr);
    return true;
}

void HelloWorld::touch2Move(Ref *obj)
{
    Vec2 playerVec = p_map->tileCoordForPosition(m_player->getPosition());
    
    Vec2 toVec = p_map->tileCoordForPosition(((Touch*)obj)->getLocation());
    
    vector<Vec2> *path = p_aStar->move2TileCoord(playerVec, toVec);
    
    Vector<FiniteTimeAction*> actions;
    for (auto v : *path)
    {
        auto moveTo = MoveTo::create(0.5f, p_map->positionForTileCoord(v));
        actions.pushBack(moveTo);
    }
    Sequence *seq = Sequence::create(actions);
    
    m_player->runAction(seq);
}

void HelloWorld::initWorldMap(string id)
{
    //初始化地图
    p_map = StageMapView::create("res/map/world_" + id + ".tmx");
    auto mapLayer = LayerManager::getInstance()->getLayerByTag(LayerType::MAP_LAYER);
    mapLayer->addChild(p_map);

    //初始化对象
    auto groups = p_map->getMap()->getObjectGroup("Key");
    auto& objs = groups->getObjects();
    for (auto& o : objs) {
        ValueMap& dict = o.asValueMap();
        string name = dict["name"].asString();
        if (name == "player")
        {
            auto ve = p_map->tileCoordForPosition(Point(dict["x"].asFloat(), dict["y"].asFloat()));
            auto pos = p_map->positionForTileCoord(ve);
            m_player = RoleSprite::create("res/grossinis.png");
            mapLayer->addChild(m_player);
            m_player->setPosition(pos);
        }
    }
    
    auto land = p_map->getMap()->getLayer("Road");
    
    p_aStar = new AStarPathSearch(land);
    p_aStar->init("", p_map->getMap()->getMapSize().width, p_map->getMap()->getMapSize().height);
    
}

//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}
