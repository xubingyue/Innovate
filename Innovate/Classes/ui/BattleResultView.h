//
//  BattleResultView.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/3.
//
//

#ifndef BattleResultView_hpp
#define BattleResultView_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"

struct DropItem {
    int dropId;
    int count;
};

enum BattleResultType{
    WIN,
    FAIL,
    ESCAPE
};

class BattleResultView : public cocos2d::Layer
{
public:
    static BattleResultView* create(int flag, int monsterId);
    
    BattleResultView();
    ~BattleResultView();
    
    bool init(int flag, int monsterId);
private:
    //触摸事件
    void touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    
    //获取掉落物品
    void getDorpList(int monsterId, std::vector<DropItem> &list);
    DropItem getDropItem(int dropId);
    
private:
    //ui跟节点
    Node *p_root;
};


#endif /* BattleResultView_hpp */
