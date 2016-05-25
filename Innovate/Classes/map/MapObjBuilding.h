//
//  MapObjBuilding.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/25.
//
//

#ifndef MapObjBuilding_hpp
#define MapObjBuilding_hpp

#include "MapObjBase.h"

class MapObjBuilding : public MapObjBase
{
public:
    static MapObjBuilding* create(std::string str);
};


#endif /* MapObjBuilding_hpp */
