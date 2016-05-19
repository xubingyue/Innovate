//
//  BattleController.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/19.
//
//

#ifndef BattleController_hpp
#define BattleController_hpp

#include "BattleView.h"

class BattleController
{
public:
    static BattleController* getInstance();
    
    BattleController();
    ~BattleController();
  
    //判断是否进入战斗
    bool isEnterBattle();
    
    //打开战斗界面
    void showBattle(std::string mapId, cocos2d::Vec2 point);
};

#endif /* BattleController_hpp */
