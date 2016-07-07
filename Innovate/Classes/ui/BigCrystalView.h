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

class BigCrystalView : public cocos2d::Layer
{
public:
    static BigCrystalView* create();
    
    BigCrystalView();
    ~BigCrystalView();
    
    bool init();
    
private:
    //触摸事件
    void touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    //切换分页
    void shiftPageCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    //背包消息返回
    void touchBagEle(Ref *obj);
    
private:
    //ui跟节点
    Node *p_root;
    //view node
    Node *p_viewNode;
    //二级背包节点
    Node *p_bagNode;
    //已选元素1
    int p_selectedId1;
    //已选元素2
    int p_selectedId2;
    //所选按钮
    int p_selectedBtn;
};

#pragma mark ---------------------元素合成界面---------------------
class SynthesisView : public cocos2d::Layer
{
public:
    static SynthesisView* create();
    
    SynthesisView();
    ~SynthesisView();
    
    bool init();
private:
    //ui跟节点
    Node *p_root;
};

#pragma mark ---------------------装备附魔界面---------------------
class EnchantView : public cocos2d::Layer
{
public:
    static EnchantView* create();
    
    EnchantView();
    ~EnchantView();
    
    bool init();
private:
    //ui跟节点
    Node *p_root;
};

#pragma mark ---------------------元素生产界面---------------------
class ProduceView : public cocos2d::Layer
{
public:
    static ProduceView* create();
    
    ProduceView();
    ~ProduceView();
    
    bool init();
private:
    //ui跟节点
    Node *p_root;
};


#endif /* BigCrystalView_hpp */
