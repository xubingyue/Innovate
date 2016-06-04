//
//  BagModel.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/2.
//
//

#include "BagModel.h"
#include "../core/utils/StringUtil.h"
#include "LocalDataManager.h"

#pragma mark ============BagItem==============

std::string BagItem::toString()
{
    
    return "";
}

#pragma mark ============BagItemWithCount=============
//bool BagItemWithCount::operator==(const BagItemWithCount &a)
//{
//    return this->item->itemId == a.item->itemId;
//}

#pragma mark ============BagModel==============
static BagModel* _instance = nullptr;

BagModel* BagModel::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new BagModel();
    }
    return _instance;
}


BagModel::BagModel()
{
    eleItemList = new vector<BagItemWithCount*>();
}

BagModel::~BagModel()
{
    
}

void BagModel::initData(string ele)
{
    string str = LocalDataManager::getInstance()->getEleBagItems();
    string delim1 = ";";
    vector<string> *items = new vector<string>();
    StringUtil::split(str, delim1, items);
    string delim2 = ",";
    for (string itemStr : *items)
    {
        vector<string> *prop = new vector<string>();
        StringUtil::split(itemStr, delim2, prop);
        
        BagItem *item = new BagItem();
        item->itemId = StringUtil::stringToInt((*prop)[0]);
        
        BagItemWithCount *biwc = new BagItemWithCount();
        biwc->item = item;
        biwc->count = StringUtil::stringToInt((*prop)[1]);
        
        eleItemList->push_back(biwc);
        
        delete prop;
    }
    delete items;
}

//向背包中添加物品
void BagModel::addItem(BagItem *item, int count)
{
    if(item->type == BagType::ELEMENT)
    {
        for (int i = 0; i < count; i++)
        {
            BagItemWithCount *biwc = new BagItemWithCount();
            biwc->item = item;
            biwc->count = 1;
            
            int idx = isExist(biwc, eleItemList);
            if (idx == -1)
            {
                eleItemList->push_back(biwc);
            } else {
                (*eleItemList)[idx]->count++;
            }
        }
    }
    //持久化数据
    string items = toEleString();
    LocalDataManager::getInstance()->setEleBagItems(items);
}

//删除背包中的
void BagModel::deleteItem(int itemId, int count)
{
    
}

int BagModel::isExist(BagItemWithCount *item, vector<BagItemWithCount*> *list)
{
    for (int i = 0; i < list->size(); i++)
    {
        if (item->item->itemId == (*list)[i]->item->itemId)
        {
            return i;
        }
    }
    return -1;
}

string BagModel::toEleString()
{
    string str = "";
    for (int i = 0; i < eleItemList->size(); i++)
    {
        auto ele = (*eleItemList)[i];
        str = str + StringUtil::intToString(ele->item->itemId) + "," + StringUtil::intToString(ele->count);
        if (i != eleItemList->size() - 1)
        {
            str += ";";
        }
    }
    return str;
}



