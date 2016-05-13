//
//  LoadingScene.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/13.
//
//

#ifndef LoadingScene_h
#define LoadingScene_h

#include "cocos2d.h"

class LoadingScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void runOnce(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(LoadingScene);
};


#endif /* LoadingScene_h */
