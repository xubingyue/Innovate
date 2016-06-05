//
//  GlobalModel.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/30.
//
//

#ifndef GlobalModel_hpp
#define GlobalModel_hpp

#include "ModelBase.h"

class GlobalModel : public ModelBase
{
public:
    static GlobalModel* getInstance();
    
public:
    //当前能量：移动步数
    int MoveSteps;
    //当前地图id数据
    int currMapId;
};

#endif /* GlobalModel_hpp */
