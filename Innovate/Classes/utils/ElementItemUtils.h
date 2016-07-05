//
//  ElementItemUtils.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/7/5.
//
//

#ifndef ElementItemUtils_hpp
#define ElementItemUtils_hpp

#include "cocos2d.h"
#include "../core/data/DataManager.h"

class ElementItemUtils
{
public:
    static ElementItemUtils* getInstance();
    //根据合成元素id获取vo
    tables::Item_compose_table* getItemComposeVo(int composeId);
    //根据两个合成原料id获取vo
    tables::Item_compose_table* getItemComposeVo(int key1, int key2);
    //准备数据
    void initComposeData();

private:
    
private:
    std::map<std::string, tables::Item_compose_table> p_data;
};

#endif /* ElementItemUtils_hpp */
