//
//  BagView.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/2.
//
//

#ifndef BagView_hpp
#define BagView_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class BagView : public cocos2d::Layer
{
public:
    static BagView* create();
    
    BagView();
    ~BagView();
    
    bool init();
    //设置宽高
    void setContentSize(cocos2d::Size s);
private:
    //触摸事件
    void touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    
private:
    //ui跟节点
    Node *p_root;
    //滚动层
    cocos2d::ui::ScrollView *p_scrollView;
    //按钮节点
    Node *p_btnNode;
};

#endif /* BagView_hpp */
