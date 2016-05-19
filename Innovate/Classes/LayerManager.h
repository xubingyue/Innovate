//
//  LayerManager.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/14.
//
//

#ifndef LayerManager_hpp
#define LayerManager_hpp

#include "cocos2d.h"

USING_NS_CC;

enum LayerType {
    MAP_LAYER = 10,
    BATTLE_LAYER = 30,
    UI_LAYER = 50
};

//层级管理器
class LayerManager
{
public:
    LayerManager();
    ~LayerManager();
    
    static LayerManager* getInstance();
   
    //初始化层级管理器
    void initLayer(Node *root);
    //获取层级
    Node* getLayerByTag(LayerType lt);
    
private:
    Node *p_root;

};

#endif /* LayerManager_hpp */
