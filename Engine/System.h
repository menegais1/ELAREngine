//
// Created by menegais1 on 27/10/2020.
//

#ifndef ENGINE_SYSTEM_H
#define ENGINE_SYSTEM_H

#include "Entity.h"

class System {
public:
    virtual void update() = 0;
    Signature signature;
};

#endif //ENGINE_SYSTEM_H
