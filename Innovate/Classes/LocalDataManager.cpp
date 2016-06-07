//
//  LocalDataManager.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#include "LocalDataManager.h"
#include "LocalDataUtil.h"
#include "StringUtil.h"


static LocalDataManager* _instance = nullptr;

LocalDataManager* LocalDataManager::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new LocalDataManager();
    }
    return _instance;
}

void LocalDataManager::init(string key)
{
    this->KEY = key;
}


bool LocalDataManager::getFirstOpen()
{
    string key = KEY + "getFirstOpen";
    return LocalDataUtil::getInstance()->getBoolForKey(key.c_str());
}
void LocalDataManager::setFirstOpen(bool flag)
{
    string key = KEY + "getFirstOpen";
    LocalDataUtil::getInstance()->setBoolForKey(key.c_str(), flag);
}

int LocalDataManager::getFarthestMap()
{
    string key = KEY + "getFarthestMap";
    return LocalDataUtil::getInstance()->getIntegerForKey(key.c_str());
}
void LocalDataManager::setFarthestMap(int mapId)
{
    string key = KEY + "getFarthestMap";
    LocalDataUtil::getInstance()->setIntegerForKey(key.c_str(), mapId);

}

int LocalDataManager::getCurrFubenId()
{
    string key = KEY + "getCurrFubenId";
    return LocalDataUtil::getInstance()->getIntegerForKey(key.c_str());
}
void LocalDataManager::setCurrFubenId(int fubenId)
{
    string key = KEY + "getCurrFubenId";
    LocalDataUtil::getInstance()->setIntegerForKey(key.c_str(), fubenId);
}

int LocalDataManager::getCurrMapId()
{
    string key = KEY + "getCurrMapId";
    return LocalDataUtil::getInstance()->getIntegerForKey(key.c_str());
}
void LocalDataManager::setCurrMapId(int mapId)
{
    string key = KEY + "getCurrMapId";
    LocalDataUtil::getInstance()->setIntegerForKey(key.c_str(), mapId);
}

int LocalDataManager::getPlayerLv()
{
    string key = KEY + "getPlayerLv";
    return LocalDataUtil::getInstance()->getIntegerForKey(key.c_str());
}
void LocalDataManager::setPlayerLv(int lv)
{
    string key = KEY + "getPlayerLv";
    LocalDataUtil::getInstance()->setIntegerForKey(key.c_str(), lv);
}

Point LocalDataManager::getPlayerPoint()
{
    string key = KEY + "getPlayerPoint";
    string pos = LocalDataUtil::getInstance()->getStringForKey(key.c_str());
    if (pos == "")
    {
        return Point(-1, -1);
    }
    vector<std::string> ret;
    string str = ",";
    StringUtil::split(pos, str, &ret);
    return Point(StringUtil::stringToInt(ret[0]), StringUtil::stringToInt(ret[1]));
}
void LocalDataManager::setPlayerPoint(Point p)
{
    string key = KEY + "getPlayerPoint";
    string v = StringUtil::intToString(p.x) + "," + StringUtil::intToString(p.y);
    LocalDataUtil::getInstance()->setStringForKey(key.c_str(), v);
}

Point LocalDataManager::getPlayerPoint4Fuben()
{
    string key = KEY + "getPlayerPoint4Fuben";
    string pos = LocalDataUtil::getInstance()->getStringForKey(key.c_str());
    if (pos == "")
    {
        return Point(-1, -1);
    }
    vector<std::string> ret;
    string str = ",";
    StringUtil::split(pos, str, &ret);
    return Point(StringUtil::stringToInt(ret[0]), StringUtil::stringToInt(ret[1]));
}
void LocalDataManager::setPlayerPoint4Fuben(Point p)
{
    string key = KEY + "getPlayerPoint4Fuben";
    string v = StringUtil::intToString(p.x) + "," + StringUtil::intToString(p.y);
    LocalDataUtil::getInstance()->setStringForKey(key.c_str(), v);
}


int LocalDataManager::getLimitCount()
{
    string key = KEY + "getLimitCount";
    return LocalDataUtil::getInstance()->getIntegerForKey(key.c_str());
}
void LocalDataManager::setLimitCount(int count)
{
    string key = KEY + "getLimitCount";
    LocalDataUtil::getInstance()->setIntegerForKey(key.c_str(), count);
}

string LocalDataManager::getEleBagItems()
{
    string key = KEY + "getEleBagItems";
    return LocalDataUtil::getInstance()->getStringForKey(key.c_str());
}
void LocalDataManager::setEleBagItems(string items)
{
    string key = KEY + "getEleBagItems";
    LocalDataUtil::getInstance()->setStringForKey(key.c_str(), items);
}
