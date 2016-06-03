//
//  StringUtil.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/30.
//
//

#ifndef StringUtil_hpp
#define StringUtil_hpp


class StringUtil
{
public:
    //int转string
    static std::string intToString(int num);
    //string转int
    static int stringToInt(std::string str);
    //string转float
    static int stringToFloat(std::string str);
    //字符串分割
    static void split(std::string& s, std::string& delim,std::vector< std::string >* ret);
};

#endif /* StringUtil_hpp */
