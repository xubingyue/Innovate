//
//  LanguageUtil.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/6.
//
//

#include "LanguageUtil.h"
#include "../data/DataManager.h"

static cocos2d::LanguageType p_lt = cocos2d::LanguageType::ENGLISH;

void LanguageUtil::initLanguage(cocos2d::LanguageType lt)
{
    p_lt = lt;
}

std::string LanguageUtil::lang(int key)
{
    auto vo = LANGUAGE_TABLE->getLanguageVo(key);
    if (p_lt == cocos2d::LanguageType::CHINESE)
    {
        return vo->zh_txt;
    } else if (p_lt == cocos2d::LanguageType::ENGLISH)
    {
        return vo->en_txt;
    }
    return vo->en_txt;
}
std::string LanguageUtil::lang_1(int key, std::string para1)
{
    std::string str = "";
    auto vo = LANGUAGE_TABLE->getLanguageVo(key);
    if (p_lt == cocos2d::LanguageType::CHINESE)
    {
        str = vo->zh_txt;
    } else if (p_lt == cocos2d::LanguageType::ENGLISH)
    {
        str = vo->en_txt;
    } else {
        str = vo->en_txt;
    }
    str = str.replace(str.find("#0#"), 3, para1);
    return str;
}
std::string LanguageUtil::lang_2(int key, std::string para1, std::string para2)
{
    std::string str = "";
    auto vo = LANGUAGE_TABLE->getLanguageVo(key);
    if (p_lt == cocos2d::LanguageType::CHINESE)
    {
        str = vo->zh_txt;
    } else if (p_lt == cocos2d::LanguageType::ENGLISH)
    {
        str = vo->en_txt;
    } else {
        str = vo->en_txt;
    }
    str = str.replace(str.find("#0#"), 3, para1);
    str = str.replace(str.find("#1#"), 3, para2);
    return str;
}
std::string LanguageUtil::lang_3(int key, std::string para1, std::string para2, std::string para3)
{
    std::string str = "";
    auto vo = LANGUAGE_TABLE->getLanguageVo(key);
    if (p_lt == cocos2d::LanguageType::CHINESE)
    {
        str = vo->zh_txt;
    } else if (p_lt == cocos2d::LanguageType::ENGLISH)
    {
        str = vo->en_txt;
    } else {
        str = vo->en_txt;
    }
    str = str.replace(str.find("#0#"), 3, para1);
    str = str.replace(str.find("#1#"), 3, para2);
    str = str.replace(str.find("#2#"), 3, para3);
    return str;
}

