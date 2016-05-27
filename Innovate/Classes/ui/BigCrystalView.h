//
//  BigCrystalView.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#ifndef BigCrystalView_hpp
#define BigCrystalView_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class BigCrystalView  : public cocos2d::Layer
{
public:
    static BigCrystalView* create();
    
    BigCrystalView();
    ~BigCrystalView();
    
    bool init();
    
private:
    //触摸事件
    void touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    
private:
    //ui跟节点
    Node *p_root;
};
#endif /* BigCrystalView_hpp */
