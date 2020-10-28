#ifndef ENGINE_SYSTEM_H
#define ENGINE_SYSTEM_H

class World;

#include "Entity.h"
#include "Query.h"
#include <set>

class System {
public:
    virtual void setup() {};

    virtual void update(World& world) = 0;

    virtual void postUpdate() {};
};

#endif