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
#include "../model/BagModel.h"

//enum class BagType

class BagView : public cocos2d::Layer
{
public:
    static BagView* create();
    
    BagView();
    ~BagView();
    
    bool init();
    //设置宽高
    void setContentSize(cocos2d::Size s);
    //打开背包
    void open(BagType index = BagType::BagType_ELEMENT, bool isShowBtn = true);
    //根据元素筛选打开背包
    void open(BagType index, int itemId1, int itemId2, bool isShowBtn = false);
private:
    //触摸事件
    void touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    
    //切换背包
    void shiftBagEvent(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    
    void onTouchEnded(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    
private:
    //ui跟节点
    Node *p_root;
    //滚动层
    cocos2d::ui::ScrollView *p_scrollView;
    //按钮节点
    Node *p_btnNode;
    //btn_1
    cocos2d::ui::Button *p_btn_1;
    cocos2d::ui::Button *p_btn_2;
    cocos2d::ui::Button *p_btn_3;
    cocos2d::ui::Button *p_btn_4;
    cocos2d::ui::Button *p_btn_5;
};

#endif /* BagView_hpp */
