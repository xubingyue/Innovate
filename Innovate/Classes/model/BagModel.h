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

enum BagType {
    ELEMENT = 1
};

class BagItem {
public:
    string toString();
public:
    int type;
    int itemId;
    string name;
    string icon;
    int quality;
    int otherId;
    string expand1;
    string expand2;
    string expand3;
    string expand4;
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
    
public:
    vector<BagItem*> *bagItemList;
};

#endif /* BagModel_hpp */
