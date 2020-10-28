#pragma once

#include "Entity.h"
#include <set>

class System {

public:
    virtual void update() = 0;
    Signature signature;
    std::set<Entity> entities;

    // Todo: Add this to Coordinator
    EntityManager entityManager;
};