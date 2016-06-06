#include "HelloWorldScene.h"
#include "DataManager.h"
#include "MemManager.h"
#include "LayerManager.h"
#include "NotificationType.h"
#include "LocalDataManager.h"
#include "BattleController.h"
#include "MapObjDisplay.h"
#include "MapObjBuilding.h"
#include "UIComponent.h"
#include "ui/BigCrystalView.h"
#include "GlobalModel.h"
#include "StringUtil.h"
#include "MapTransferView.h"

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
    
    UIComponent::getInstance(LayerManager::getInstance()->getLayerByTag(LayerType::UI_LAYER));

    int mapId = LocalDataManager::getInstance()->getCurrMapId();
    if (mapId == 0)
    {
        mapId = 1;
        LocalDataManager::getInstance()->setCurrMapId(1);
    }
    //初始化世界地图
    auto mapVo = SCENE_MAP_TABLE->getScene_mapVo(mapId);
//    GlobalModel::getInstance()->currMapId = mapId;
    GlobalModel::getInstance()->setCurrMapInfo(mapId);
    initWorldMap(mapVo->map_name);
    initPosition();
    
//    int temp = 99;
//    
//    m_int sto = MemManager::getInstance()->encode(temp);
//    
//    CCLOG("%d ===== %s", sto.value, sto.md5.c_str());
//    
//    int result = MemManager::getInstance()->decode(sto);
//    
//    CCLOG("====>>>>>%d", result);
    //人物寻路
    __NotificationCenter::getInstance()->addObserver(this, CC_CALLFUNCO_SELECTOR
                                                     (HelloWorld::touch2Move),
                                                     TOUCH_MAP_TO_MOVE, nullptr);
    //死亡重置
    __NotificationCenter::getInstance()->addObserver(this, CC_CALLFUNCO_SELECTOR
                                                     (HelloWorld::dieResetPos),
                                                     BATTLE_DIE_TO_CRYSTAL, nullptr);
    //切换地图
    __NotificationCenter::getInstance()->addObserver(this, CC_CALLFUNCO_SELECTOR
                                                     (HelloWorld::gotoSeleteMap),
                                                     GO_TO_SELETE_MAP, nullptr);
    return true;
}

void HelloWorld::touch2Move(Ref *obj)
{
    if (p_isFinding)
    {
        CCLOG("正在寻路，保存队列");
        p_targetPoint = ((Touch2MoveData*)obj)->end;
        p_buildId = ((Touch2MoveData*)obj)->buildId;
        p_isNull = false;
        return;
    }
    //保存人物当前坐标
    p_prePoint = m_player->getPosition();
    
    Point toVec;
    if (obj == nullptr)//队列中缓存的目标点
    {
        toVec = p_targetPoint;
    } else {
        toVec = ((Touch2MoveData*)obj)->end;
        p_buildId = ((Touch2MoveData*)obj)->buildId;
    }
    Vec2 playerVec = p_map->tileCoordForPosition(m_player->getPosition());
    
    vector<Vec2> *path = new vector<Vec2>();
    path = p_aStar->findPath(playerVec, toVec, path);
    GlobalModel::getInstance()->findPathMaxSteps = path->size() - 1;
    if (path == nullptr) {
        if (p_buildId != -1)
        {
            openByBuildId(p_buildId);
        }
        return;
    }
    //设置目标点颜色
    if (p_sp) p_sp->setColor(p_color);
    auto land = p_map->getMap()->getLayer(ROAD_LAYER);
    p_sp = land->getTileAt(toVec);
    p_color = p_sp->getColor();
    p_sp->setColor(Color3B::GREEN);
    //进入寻路状态
    p_isFinding = true;
    
    Vector<FiniteTimeAction*> actions;
    for (int i = 1; i < path->size(); i++)
    {
        auto v = (*path)[i];
        auto moveTo = MoveTo::create(0.3f, p_map->positionForTileCoord(v));
        actions.pushBack(moveTo);
        auto callFun = CallFunc::create( CC_CALLBACK_0(HelloWorld::moveCallBack,this));
        actions.pushBack(callFun);
    }
    
    auto callFun = CallFunc::create( CC_CALLBACK_0(HelloWorld::movesCallBack,this));
    actions.pushBack(callFun);

    Sequence *seq = Sequence::create(actions);
    this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateMapByPlayer), 0.01, CC_REPEAT_FOREVER, 0);
    this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::updatePlayerZorder), 0.2, CC_REPEAT_FOREVER, 0);
    m_player->runAction(seq);
    
    //清除
    delete path;
    delete obj;
}

void HelloWorld::initWorldMap(string map)
{
    //初始化地图
    p_map = StageMapView::create("res/map/" + map + ".tmx");
//    p_map->setScale(1.5);
    auto mapLayer = LayerManager::getInstance()->getLayerByTag(LayerType::MAP_LAYER);
    mapLayer->addChild(p_map);
    auto land = p_map->getMap()->getLayer(ROAD_LAYER);

    //初始化对象
    auto groups = p_map->getMap()->getObjectGroup(OBJ_LAYER);
    auto& objs = groups->getObjects();
    for (auto& o : objs) {
        ValueMap& dict = o.asValueMap();
        int id = dict["type"].asInt();
        if (id == 1)//1:固定是玩家
        {
            auto ve = p_map->tileCoordForPosition(Point(dict["x"].asFloat(), dict["y"].asFloat()));
            Point pos = LocalDataManager::getInstance()->getPlayerPoint();
//            pos = p_map->positionForTileCoord(ve);
            if (pos == Point(-1, -1))
            {
                pos = p_map->positionForTileCoord(ve);
            } else {
                pos = p_map->positionForTileCoord(pos);
            }
            auto obj = OBJECT_TABLE->getObjectVo(1);
            m_player = RoleSprite::create(obj->res);
            m_player->setAnchorPoint(Vec2(0.5, 0));
            p_map->addToMap(m_player, ve);
            m_player->setTag(PLAYER_TAG);
            m_player->setPosition(pos);
            p_initPos = ve;
        } else {
            auto obj = OBJECT_TABLE->getObjectVo(id);
            if (obj->type == ObjectType::OT_DISPLAY)
            {
                auto ve = p_map->tileCoordForPosition(Point(dict["x"].asFloat(), dict["y"].asFloat()));
                auto pos = p_map->positionForTileCoord(ve);
                auto display = MapObjDisplay::create(obj->res);
                display->setAnchorPoint(Point(0.5, 0));
                p_map->addToMap(display, ve);
                display->setPosition(pos);
            }
            else if (obj->type == ObjectType::OT_CRYSTAL || obj->type == ObjectType::OT_TRANSFER || obj->type == ObjectType::OT_FUBEN)
            {
                auto ve = p_map->tileCoordForPosition(Point(dict["x"].asFloat(), dict["y"].asFloat()));
                #pragma mark 特殊处理建筑坐标减1
                ve = ve - Point(0, 1);
                auto pos = p_map->positionForTileCoord(ve);
                auto display = MapObjBuilding::create(obj->res);
                display->setAnchorPoint(Point(0, 0));
                p_map->addToMap(display, ve);
                p_map->addObjToVec(display);    //将需要碰撞的建筑放到碰撞集合中
                display->setPosition(pos - Point(TILED_SIZE/2, TILED_SIZE/2));
                display->initData(ve, land);
                display->buildId = id;
            }
            else if (obj->type == ObjectType::OT_DISPLAY)
            {
                auto ve = p_map->tileCoordForPosition(Point(dict["x"].asFloat(), dict["y"].asFloat()));
#pragma mark 特殊处理建筑坐标减1
                ve = ve - Point(0, 1);
                auto pos = p_map->positionForTileCoord(ve);
                auto display = MapObjBuilding::create(obj->res);
                display->setAnchorPoint(Point(0, 0));
                p_map->addToMap(display, ve);
                display->setPosition(pos - Point(TILED_SIZE/2, TILED_SIZE/2));
            }
        }
    }
    
    p_aStar = new AStarFindPath(land, p_map->getMap()->getMapSize().width, p_map->getMap()->getMapSize().height);
}

void HelloWorld::initPosition()
{
    auto mapLayer = LayerManager::getInstance()->getLayerByTag(LayerType::MAP_LAYER);
    mapLayer->setPosition(Point(0, 0));
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

void HelloWorld::updatePlayerZorder(float dt)
{
    Point pp = m_player->getPosition();
    Point v = p_map->tileCoordForPosition(pp);
    m_player->resetZorder(v);
}

void HelloWorld::moveCallBack()
{
    GlobalModel::getInstance()->MoveSteps--;
    UIComponent::getInstance()->updateLimit(GlobalModel::getInstance()->MoveSteps);
    if (GlobalModel::getInstance()->MoveSteps <= 0)
    {
        this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateMapByPlayer));
        this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updatePlayerZorder));
        m_player->stopAllActions();
//        resetPlayerPos();
        dieEffect();
        return;
    }
    if (GlobalModel::getInstance()->stepCount == GlobalModel::getInstance()->findPathMaxSteps && p_buildId != -1)
    {
        return;//最后一步打开了建筑 就不要遇到怪物了
    }
    bool isBattle = BattleController::getInstance()->isEnterBattle();
    if (isBattle) {
        this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateMapByPlayer));
        this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updatePlayerZorder));
        m_player->stopAllActions();
        p_isNull = true;
        p_isFinding = false;
        p_sp->setColor(p_color);
        BattleController::getInstance()->showBattle("", Point(0, 0));
        return;
    }
    if (!p_isNull) {
        p_isFinding = false;
        p_isNull = true;
        m_player->stopAllActions();
        this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateMapByPlayer));
        this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updatePlayerZorder));
        touch2Move(nullptr);
    }
}

void HelloWorld::movesCallBack()
{
    //保存数据
    auto tmpPos = p_map->tileCoordForPosition(m_player->getPosition());
    LocalDataManager::getInstance()->setPlayerPoint(tmpPos);
    LocalDataManager::getInstance()->setLimitCount(GlobalModel::getInstance()->MoveSteps);
    
    this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updateMapByPlayer));
    this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::updatePlayerZorder));
    
    //寻路结束，设置状态为非寻路状态。
    p_isFinding = false;
    p_sp->setColor(p_color);
    if (p_buildId != -1)
    {
        openByBuildId(p_buildId);
        //BigCrystalView
        return;
    }
    bool isBattle = BattleController::getInstance()->isEnterBattle();
    if (isBattle) {
        BattleController::getInstance()->showBattle("", Point(0, 0));
    }
}

void HelloWorld::openByBuildId(int buildId)
{
    p_map->openBuildingById(buildId);
}

void HelloWorld::dieResetPos(Ref *obj)
{
    resetPlayerPos();
}

void HelloWorld::resetPlayerPos()
{
    p_isFinding = false;
    p_sp->setColor(p_color);
    LocalDataManager::getInstance()->setPlayerPoint(p_initPos);
    auto vo = CONFIG_TABLE->getConfigVo(2);
    int limit = StringUtil::stringToInt(vo->data);
    GlobalModel::getInstance()->MoveSteps = limit;
    LocalDataManager::getInstance()->setLimitCount(GlobalModel::getInstance()->MoveSteps);
    UIComponent::getInstance()->updateLimit(GlobalModel::getInstance()->MoveSteps);
    
    Point pos = p_map->positionForTileCoord(p_initPos);
    m_player->setPosition(pos);
    initPosition();
}

void HelloWorld::dieEffect()
{
    auto winSize = Director::getInstance()->getWinSize();
    auto la = LayerColor::create(Color4B::BLACK, winSize.width, winSize.height);
    auto topLayer = LayerManager::getInstance()->getLayerByTag(LayerType::TOP_LAYER);
    topLayer->addChild(la);
    Vector<FiniteTimeAction*> actions;
    auto in = FadeIn::create(0.5);
    auto out = FadeOut::create(1);
    auto callFun = CallFunc::create(CC_CALLBACK_0(HelloWorld::resetPlayerPos,this));
    
    actions.pushBack(in);
    actions.pushBack(callFun);
    actions.pushBack(out);
    
    auto seq = Sequence::create(actions);
    
    la->runAction(seq);
}

void HelloWorld::gotoSeleteMap(Ref *obj)
{
    auto mapObj = static_cast<MapObj4Notify*>(obj);
    auto mapVo = SCENE_MAP_TABLE->getScene_mapVo(mapObj->mapId);
    
    //清理上一张地图资源
    m_player->removeFromParentAndCleanup(true);
    p_map->removeFromParentAndCleanup(true);
    
    LocalDataManager::getInstance()->setPlayerPoint(Point(-1, -1));
    p_isNull = true;
    p_isFinding = false;
    delete p_aStar;
    
    //初始化新地图
    LocalDataManager::getInstance()->setCurrMapId(mapObj->mapId);
    int farthest = LocalDataManager::getInstance()->getFarthestMap();
    if (mapObj->mapId > farthest)
    {
        LocalDataManager::getInstance()->setFarthestMap(mapObj->mapId);
    }
    
    auto vo = CONFIG_TABLE->getConfigVo(2);
    int limit = StringUtil::stringToInt(vo->data);
    GlobalModel::getInstance()->MoveSteps = limit;
    LocalDataManager::getInstance()->setLimitCount(GlobalModel::getInstance()->MoveSteps);
    UIComponent::getInstance()->updateLimit(GlobalModel::getInstance()->MoveSteps);
    
//    GlobalModel::getInstance()->currMapId = mapObj->mapId;
    GlobalModel::getInstance()->setCurrMapInfo(mapObj->mapId);
    initWorldMap(mapVo->map_name);
    initPosition();
}

//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}
