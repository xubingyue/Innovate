//
//  UIComponent.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#ifndef UIComponent_hpp
#define UIComponent_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class UIComponent : public cocos2d::Layer
{
public:
    static UIComponent* getInstance(Node *layer = nullptr);
  
    bool init(Node *layer);
    //设置ui是否显示
    void showVisiable(bool flag);
    
private:
    //触摸事件
    void touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    
private:
    //ui跟节点
    Node *p_root;

};

#endif /* UIComponent_hpp */
