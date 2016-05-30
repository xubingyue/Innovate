//
//  LocalDataManager.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#ifndef LocalDataManager_hpp
#define LocalDataManager_hpp

#include <string>
using namespace std;

class LocalDataManager
{
public:
    string KEY;

public:
    static LocalDataManager* getInstance();
    
    void init(string key);
    
    //是否第一次登陆
    bool getFirstOpen();
    void setFirstOpen(bool flag);
    
    //玩家等级
    int getPlayerLv();
    void setPlayerLv(int lv);
    
    
};

#endif /* LocalDataManager_hpp */
