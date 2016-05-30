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
};

#endif /* GlobalModel_hpp */
