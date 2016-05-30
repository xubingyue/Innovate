//
//  GlobalModel.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/30.
//
//

#include "GlobalModel.h"

static GlobalModel* _instance = nullptr;

GlobalModel* GlobalModel::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new GlobalModel();
    }
    return _instance;
}