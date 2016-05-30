//
//  StringUtil.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/30.
//
//

#include "StringUtil.h"

std::string StringUtil::intToString(int num)
{
    std::stringstream ss;
    std::string str;
    ss<<num;
    ss>>str;
    return str;
}

int StringUtil::stringToInt(std::string s)
{
    std::stringstream ss;
    ss<<s;
    int i;
    ss>>i;
    return i;
}