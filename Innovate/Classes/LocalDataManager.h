//
//  LocalDataManager.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#ifndef LocalDataManager_hpp
#define LocalDataManager_hpp

#include <string>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class LocalDataManager
{
public:
    string KEY;

public:
    static LocalDataManager* getInstance();
    
    void init(string key);
    
    //是否第一次登陆
    bool getFirstOpen();
    void setFirstOpen(bool flag);
    
    //玩家等级
    int getPlayerLv();
    void setPlayerLv(int lv);
    
    //玩家地图位置
    Point getPlayerPoint();
    void setPlayerPoint(Point p);
    
    //能量步数
    int getLimitCount();
    void setLimitCount(int count);
};

#endif /* LocalDataManager_hpp */
