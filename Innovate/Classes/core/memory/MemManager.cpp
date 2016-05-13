//
//  MemManager.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/13.
//
//

#include "MemManager.h"
#include "md5.h"
#include <string.h>

static MemManager* _instance = nullptr;


MemManager::MemManager(void)
{
}


MemManager::~MemManager(void)
{
    
}

MemManager* MemManager::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new MemManager();
    }
    return _instance;
}

//加密函数
m_int MemManager::encode(int src)
{
    m_int a;
    std::stringstream ss;
    ss<<src;
    std::string str = ss.str();
    MD5 md5(str);
    a.value = ((src + 1) >> 1);
    a.md5 = md5.md5();
    return a;
}

m_float MemManager::encode (float src)
{
    m_float a;
    std::stringstream ss;
    ss<<src;
    std::string str = ss.str();
    MD5 md5(str);
    a.value = src + 2715.7;
    a.md5 = md5.md5();
    return a;
}

//解密函数
int MemManager::decode(m_int src)
{
    int value = ((src.value << 1) - 1);
    std::stringstream ss;
    ss<<value;
    std::string str = ss.str();
    MD5 md5(str);
    if (md5.md5() == src.md5)
    {
        return value;
    } else {
        assert("The value's md5 is wrong!!!");
    }
    return 0;
}

float MemManager::decode (m_float src)
{
    int value = src.value - 2715.7;
    std::stringstream ss;
    ss<<value;
    std::string str = ss.str();
    MD5 md5(str);
    if (md5.md5() == src.md5)
    {
        return value;
    } else {
        assert("The value's md5 is wrong!!!");
    }
    return 0;
}


