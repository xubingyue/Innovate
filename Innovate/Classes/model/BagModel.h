//
//  BagModel.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/2.
//
//

#ifndef BagModel_hpp
#define BagModel_hpp

#include "ModelBase.h"

using namespace std;

enum class BagType {
    ELEMENT = 1
};

//背包中物品item
class BagItem {
public:
    string toString();
public:
    BagType type;
    int itemId;
    string expand1;
    string expand2;
    string expand3;
    string expand4;
};

//储存物品的类型
class BagItemWithCount
{
public:
    bool operator==(const BagItemWithCount &a)
    {
        return (this->item->itemId == a.item->itemId);
    }
public:
    BagItem *item;
    int count;
};

class BagModel : public ModelBase
{
public:
    static BagModel* getInstance();
    
    BagModel();
    ~BagModel();
    
    //向背包中添加物品
    void addItem(BagItem *item, int count = 1);
    //删除背包中的
    void deleteItem(int itemId, int count = 1);
    
private:
    int isExist(BagItemWithCount *item, vector<BagItemWithCount*> *list);
    
public:
    //元素分类
    vector<BagItemWithCount*> *eleItemList;
};

#endif /* BagModel_hpp */
