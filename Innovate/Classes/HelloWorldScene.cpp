#include "HelloWorldScene.h"
#include "DataManager.h"
#include "MemManager.h"
#include "LayerManager.h"
#include "NotificationType.h"
#include "LocalDataUtil.h"
#include "BattleController.h"

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
    //没有在寻路状态
    p_isFinding = false;
    p_isNull = true;
    //初始化层级
    LayerManager::getInstance()->initLayer(this);

    string mapId = LocalDataUtil::getInstance()->getStringForKey("map", "1");
    //初始化世界地图
    initWorldMap(mapId);
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
    if (p_isFinding)
    {
        CCLOG("正在寻路，保存队列");
        p_targetPoint = ((Touch*)obj)->getLocation();
        p_isNull = false;
        return;
    }
    //保存人物当前坐标
    p_prePoint = m_player->getPosition();
    
    Point worldPoint;
    if (obj == nullptr)//队列中缓存的目标点
    {
        worldPoint = p_targetPoint;
    } else {
        worldPoint = ((Touch*)obj)->getLocation();
    }
    auto currPoint = p_map->convertToNodeSpace(worldPoint);
    Vec2 playerVec = p_map->tileCoordForPosition(m_player->getPosition());
    Vec2 toVec = p_map->tileCoordForPosition(currPoint);
    
    vector<Vec2> *path = new vector<Vec2>();
    path = p_aStar->findPath(playerVec, toVec, path);
    
    if (path == nullptr) return;
    if (p_sp) p_sp->setColor(p_color);
    auto land = p_map->getMap()->getLayer("Road");
    p_sp = land->getTileAt(toVec);
    p_color = p_sp->getColor();
    p_sp->setColor(Color3B::GREEN);
    //进入寻路状态
    p_isFinding = true;
    
    Vector<FiniteTimeAction*> actions;
    for (auto v : *path)
    {
        auto moveTo = MoveTo::create(0.3f, p_map->positionForTileCoord(v));
        actions.pushBack(moveTo);
        auto callFun = CallFunc::create( CC_CALLBACK_0(HelloWorld::moveCallBack,this));
        actions.pushBack(callFun);
    }
    auto callFun = CallFunc::create( CC_CALLBACK_0(HelloWorld::movesCallBack,this));
    actions.pushBack(callFun);

    Sequence *seq = Sequence::create(actions);
    this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateMapByPlayer), 0.01, CC_REPEAT_FOREVER, 0);
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

void HelloWorld::updateMapByPlayer(float dt)
{
    auto mapLayer = LayerManager::getInstance()->getLayerByTag(LayerType::MAP_LAYER);
    Point result = p_prePoint - m_player->getPosition();
    mapLayer->setPosition(mapLayer->getPosition() + result);
    p_prePoint = m_player->getPosition();
}

void HelloWorld::moveCallBack()
{
    CCLOG("one step over======");
    bool isBattle = BattleController::getInstance()->isEnterBattle();
    if (isBattle) {
        CCLOG("===Enter the battle!!!");
        this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateMapByPlayer));
        m_player->stopAllActions();
        p_isNull = true;
        p_isFinding = false;
        p_sp->setColor(p_color);
        BattleController::getInstance()->showBattle("", Point(0, 0));
        return;
    }
    if (!p_isNull) {
        CCLOG("开始新的寻路");
        p_isFinding = false;
        p_isNull = true;
        m_player->stopAllActions();
        this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateMapByPlayer));
        touch2Move(nullptr);
    }
}

void HelloWorld::movesCallBack()
{
    this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateMapByPlayer));
    CCLOG("all steps are over======");
    //寻路结束，设置状态为非寻路状态。
    p_isFinding = false;
    p_sp->setColor(p_color);
    bool isBattle = BattleController::getInstance()->isEnterBattle();
    if (isBattle) {
        CCLOG("===Enter the battle!!!");
        BattleController::getInstance()->showBattle("", Point(0, 0));
    }
}



//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}
