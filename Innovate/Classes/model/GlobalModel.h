//
//  GlobalModel.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/30.
//
//

#ifndef GlobalModel_hpp
#define GlobalModel_hpp

#include "ModelBase.h"

class GlobalModel : public ModelBase
{
public:
    static GlobalModel* getInstance();
    //设置当前地图信息
    void setCurrMapInfo(int mapId);
    //获得当前遇怪的概率
    int getCurrProbability();
    
public:
    //每次遇怪前的行走步数计数
    int stepCount = 0;
    //当前能量：可移动的步数
    int MoveSteps;
    //当前地图id数据
    int currMapId;
    //当前地图的最低等级
    int mapMinLevel;
    //当前地图的最高等级
    int mapMaxLevel;
    //暗雷初始概率
    float probability;
    //暗雷步长
    float probability_grow;
    //等级步长衰减
    float attenuation;
    //当此寻路的总步数
    int findPathMaxSteps;
};

#endif /* GlobalModel_hpp */
