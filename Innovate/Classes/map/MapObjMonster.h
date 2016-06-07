//
//  MapObjMonster.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/7.
//
//

#ifndef MapObjMonster_hpp
#define MapObjMonster_hpp

#include "MapObjBase.h"

class MapObjMonster : public MapObjBase
{
public:
    static MapObjMonster* create(std::string str);
};

#endif /* MapObjMonster_hpp */
