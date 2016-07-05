//
//  ElementItemUtils.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/7/5.
//
//

#include "ElementItemUtils.h"
#include "../core/utils/StringUtil.h"

static ElementItemUtils* _instance = nullptr;

ElementItemUtils* ElementItemUtils::getInstance()
{
    if (_instance == nullptr) {
        _instance = new ElementItemUtils();
    }
    return _instance;
}

void ElementItemUtils::initComposeData()
{
//    p_data
    auto composeData = GET_ITEM_COMPOSE_DATA;
    
    std::map<std::string, tables::Item_compose_table>::iterator it = composeData->begin();
    while (it != composeData->end()) {
        tables::Item_compose_table *vo = &(it->second);
        std::string key = StringUtil::intToString(vo->item_1) + "_" + StringUtil::intToString(vo->item_2);
        p_data[key] = *vo;
        it++;
    }
}

//根据合成元素id获取vo
tables::Item_compose_table* ElementItemUtils::getItemComposeVo(int composeId)
{
    return ITEM_COMPOSE_TABLE->getItem_composeVo(composeId);
}

//根据两个合成原料id获取vo
tables::Item_compose_table* ElementItemUtils::getItemComposeVo(int key1, int key2)
{
    auto it = p_data.find(StringUtil::intToString(key1) + "_" + StringUtil::intToString(key2));
    if (it == p_data.end())
    {
        return nullptr;
    } else {
        return &((*it).second);
    }
}