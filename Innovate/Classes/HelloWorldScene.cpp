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

    //初始化层级
    LayerManager::getInstance()->initLayer(this);

    //初始化世界地图
    initWorldMap();
    initPosition();

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
    auto worldPoint = ((Touch*)obj)->getLocation();
    auto currPoint = p_map->convertToNodeSpace(worldPoint);
    Vec2 playerVec = p_map->tileCoordForPosition(m_player->getPosition());
    Vec2 toVec = p_map->tileCoordForPosition(currPoint);
    
    auto ss = Sprite::create();
    ss->getColor();
    
    vector<Vec2> *path = new vector<Vec2>();
    path = p_aStar->findPath(playerVec, toVec, path);
    
    Vector<FiniteTimeAction*> actions;
    for (auto v : *path)
    {
        auto moveTo = MoveTo::create(0.3f, p_map->positionForTileCoord(v));
        actions.pushBack(moveTo);
    }
    Sequence *seq = Sequence::create(actions);
    m_player->runAction(seq);
    delete path;
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
            m_player->setAnchorPoint(Vec2(0.5, 0));
            mapLayer->addChild(m_player);
            m_player->setPosition(pos);
        }
    }
    
    auto land = p_map->getMap()->getLayer("Road");
    
    p_aStar = new AStarFindPath(land, p_map->getMap()->getMapSize().width, p_map->getMap()->getMapSize().height);
}

void HelloWorld::initPosition()
{
    auto mapLayer = LayerManager::getInstance()->getLayerByTag(LayerType::MAP_LAYER);
    Size winSize = Director::getInstance()->getWinSize();
    
    Point center = Point(winSize.width/2, winSize.height/2);
    Point player = m_player->getPosition();
    Point result = player - center;
    mapLayer->setPosition(mapLayer->getPosition() - result);
}

//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}
