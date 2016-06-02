//
//  BagModel.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/2.
//
//

#include "BagModel.h"

#pragma mark ============BagItem==============

std::string BagItem::toString()
{
    
    return "";
}



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
    bagItemList = new vector<BagItem*>();
}

BagModel::~BagModel()
{
    
}

//向背包中添加物品
void BagModel::addItem(BagItem *item, int count)
{
    
}

//删除背包中的
void BagModel::deleteItem(int itemId, int count)
{
    
}




