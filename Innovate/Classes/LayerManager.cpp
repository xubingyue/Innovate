//
//  LayerManager.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/14.
//
//

#include "LayerManager.h"

static LayerManager* _instance = nullptr;


LayerManager::LayerManager()
{
}


LayerManager::~LayerManager()
{
    
}

LayerManager* LayerManager::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new LayerManager();
    }
    return _instance;
}

void LayerManager::initLayer(Node *root)
{
    p_root = root;
    
    auto mapLayer = Node::create();
    p_root->addChild(mapLayer, LayerType::MAP_LAYER);
    mapLayer->setTag(LayerType::MAP_LAYER);
    
    auto uiLayer = Node::create();
    p_root->addChild(uiLayer, LayerType::UI_LAYER);
    uiLayer->setTag(LayerType::UI_LAYER);
}

Node* LayerManager::getLayerByTag(LayerType lt)
{
    return p_root->getChildByTag(lt);
}

