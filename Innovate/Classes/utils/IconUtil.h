//
//  IconUtil.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/3.
//
//

#ifndef IconUtil_hpp
#define IconUtil_hpp

#include "cocos2d.h"

//图标类型
enum IconType
{
    IconType_ELEMENT,//元素
    IconType_ELF//精灵
};

class IconUtil
{
public:
    static IconUtil* getInstance();
    
    cocos2d::Node* getIconById(IconType type, int id, int count);
};

#endif /* IconUtil_hpp */
