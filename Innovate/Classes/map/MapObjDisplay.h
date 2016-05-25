//
//  MapObjDisplay.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/25.
//
//

#ifndef MapObjDisplay_hpp
#define MapObjDisplay_hpp

#include "MapObjBase.h"

class MapObjDisplay : public MapObjBase
{
public:
    static MapObjDisplay* create(std::string str);
};

#endif /* MapObjDisplay_hpp */
