//
//  MemManager.h
//  Innovate
//
//  Created by YUEBINBIN on 16/5/13.
//
//

#ifndef MemManager_h
#define MemManager_h

#include "cocos2d.h"
using namespace std;

struct m_int {
    int value;
    string md5;
};

struct m_float {
    float value;
    string md5;
};

class MemManager {

public:
    MemManager(void);
    ~MemManager(void);
    
    static MemManager* getInstance();
    
    //加密函数
    m_int encode(int src);
    m_float encode (float src);
    //解密函数
    int decode(m_int src);
    float decode (m_float src);
    
};

#endif /* MemManager_h */
