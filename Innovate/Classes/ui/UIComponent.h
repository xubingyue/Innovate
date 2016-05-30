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
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocos2d::ui;


class UIComponent : public cocos2d::Layer
{
public:
    static UIComponent* getInstance(Node *layer = nullptr);
  
    bool init(Node *layer);
    //设置ui是否显示
    void showVisiable(bool flag);
    //更新能量步数
    void updateLimit(int num);
    
private:
    //触摸事件
    void touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    
private:
    //ui跟节点
    Node *p_root;
    //步数限制
    Text *p_limitValue;

};

#endif /* UIComponent_hpp */
