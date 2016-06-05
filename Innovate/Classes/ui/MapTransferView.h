//
//  MapTransferView.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/4.
//
//

#ifndef MapTransferView_hpp
#define MapTransferView_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MapTransferView : public cocos2d::Layer
{
public:
    static MapTransferView* create(int currMapId);
    
    MapTransferView();
    ~MapTransferView();
    
    bool init(int currMapId);
    
private:
    //触摸事件
    void touchEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
    //返回事件
    void backEventCallback(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
};

#endif /* MapTransferView_hpp */
