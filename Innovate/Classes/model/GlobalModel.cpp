//
//  GlobalModel.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/30.
//
//

#include "GlobalModel.h"
#include "../core/data/DataManager.h"

static GlobalModel* _instance = nullptr;

GlobalModel* GlobalModel::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new GlobalModel();
    }
    return _instance;
}

void GlobalModel::setCurrMapInfo(int mapId)
{
    //当前地图id数据
    currMapId = mapId;
    auto vo = SCENE_MAP_TABLE->getScene_mapVo(mapId);
    
    //当前地图的最低等级
    mapMinLevel = vo->minLevel;
    //当前地图的最高等级
    mapMaxLevel = vo->maxLevel;
    //暗雷初始概率
    probability = vo->probability;
    //暗雷步长
    probability_grow = vo->probability_grow;
    //等级步长衰减
    attenuation = vo->attenuation;
}

int GlobalModel::getCurrProbability()
{
    
}




