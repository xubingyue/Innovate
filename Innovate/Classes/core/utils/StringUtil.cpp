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