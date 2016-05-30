//
//  PlayerView.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#ifndef PlayerView_hpp
#define PlayerView_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class PlayerView  : public cocos2d::Layer
{
public:
    static PlayerView* create();
    
    PlayerView();
    ~PlayerView();
    
    bool init();

private:
    //触摸事件
    void touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);

private:
    //ui跟节点
    Node *p_root;
    Node *p_playerNode;
};

#endif /* PlayerView_hpp */
