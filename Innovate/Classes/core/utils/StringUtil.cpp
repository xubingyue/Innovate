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

void StringUtil::split(std::string& s, std::string& delim,std::vector< std::string >* ret)
{
    size_t last = 0;
    size_t index=s.find_first_of(delim,last);
    while (index!=std::string::npos)
    {
        ret->push_back(s.substr(last,index-last));
        last=index+1;
        index=s.find_first_of(delim,last);
    }
    if (index-last>0)
    {
        ret->push_back(s.substr(last,index-last));
    }
}