//
//  LocalDataUtil.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/18.
//
//

#include "LocalDataUtil.h"

USING_NS_CC;

static LocalDataUtil* _instance = nullptr;

LocalDataUtil* LocalDataUtil::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new LocalDataUtil();
    }
    return _instance;
}

LocalDataUtil::LocalDataUtil()
{
    
}

LocalDataUtil::~LocalDataUtil()
{
    
}

bool LocalDataUtil::getBoolForKey(const char* key)
{
    return UserDefault::getInstance()->getBoolForKey(key);
}
bool LocalDataUtil::getBoolForKey(const char* key, bool defaultValue)
{
    return UserDefault::getInstance()->getBoolForKey(key, defaultValue);
}

int LocalDataUtil::getIntegerForKey(const char* key)
{
    return UserDefault::getInstance()->getIntegerForKey(key);
}
int LocalDataUtil::getIntegerForKey(const char* key, int defaultValue)
{
    return UserDefault::getInstance()->getIntegerForKey(key, defaultValue);
}

float LocalDataUtil::getFloatForKey(const char* key)
{
    return UserDefault::getInstance()->getFloatForKey(key);
}
float LocalDataUtil::getFloatForKey(const char* key, float defaultValue)
{
    return UserDefault::getInstance()->getFloatForKey(key, defaultValue);
}

double LocalDataUtil::getDoubleForKey(const char* key)
{
    return UserDefault::getInstance()->getDoubleForKey(key);
}
double LocalDataUtil::getDoubleForKey(const char* key, double defaultValue)
{
    return UserDefault::getInstance()->getDoubleForKey(key, defaultValue);
}

std::string LocalDataUtil::getStringForKey(const char* key)
{
    return UserDefault::getInstance()->getStringForKey(key);
}
std::string LocalDataUtil::getStringForKey(const char* key, const std::string & defaultValue)
{
    return UserDefault::getInstance()->getStringForKey(key, defaultValue);
}

void LocalDataUtil::setIntegerForKey(const char* key, int value)
{
    UserDefault::getInstance()->setIntegerForKey(key, value);
}
void LocalDataUtil::setFloatForKey(const char* key, float value)
{
    UserDefault::getInstance()->setFloatForKey(key, value);
}
void LocalDataUtil::setDoubleForKey(const char* key, double value)
{
    UserDefault::getInstance()->setDoubleForKey(key, value);
}
void LocalDataUtil::setStringForKey(const char* key, const std::string & value)
{
    UserDefault::getInstance()->setStringForKey(key, value);
}
void LocalDataUtil::setBoolForKey(const char* key, bool value)
{
    UserDefault::getInstance()->setBoolForKey(key, value);
}

void LocalDataUtil::flush()
{
    UserDefault::getInstance()->flush();
}

void LocalDataUtil::deleteValueForKey(const char* key)
{
    UserDefault::getInstance()->deleteValueForKey(key);
}

