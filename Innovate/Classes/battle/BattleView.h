//
//  BattleView.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/19.
//
//

#ifndef BattleView_hpp
#define BattleView_hpp

#include "cocos2d.h"
USING_NS_CC;

class BattleView : public cocos2d::Layer
{
public:
    static BattleView* create();
    
    virtual bool init() override;
    
    virtual void onEnter() override;
    virtual void onExit() override;

private:
    //touch
    bool onTouchBegan(Touch *touch, Event *unused_event) override;
    void onTouchMoved(Touch *touch, Event *unused_event) override;
    void onTouchEnded(Touch *touch, Event *unused_event) override;
};

#endif /* BattleView_hpp */
