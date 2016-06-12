//
//  LanguageUtil.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/6.
//
//

#ifndef LanguageUtil_hpp
#define LanguageUtil_hpp

#include "cocos2d.h"

class LanguageUtil
{
public:
    static void initLanguage(cocos2d::LanguageType lt);
    static std::string lang(int key);
    static std::string lang_1(int key, std::string para1);
    static std::string lang_2(int key, std::string para1, std::string para2);
    static std::string lang_3(int key, std::string para1, std::string para2, std::string para3);
    
private:
    
};

#endif /* LanguageUtil_hpp */
