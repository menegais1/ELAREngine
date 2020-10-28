#ifndef ENGINE_SYSTEM_H
#define ENGINE_SYSTEM_H


#include "Entity.h"
#include <set>

class System {
public:
    virtual void setup() {};

    virtual void update() = 0;

    virtual void postUpdate() {};
};

#endif