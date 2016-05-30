//
//  LocalDataManager.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#include "LocalDataManager.h"
#include "LocalDataUtil.h"


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



