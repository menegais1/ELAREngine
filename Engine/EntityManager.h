//
// Created by menegais1 on 27/10/2020.
//

#ifndef ENGINE_ENTITYMANAGER_H
#define ENGINE_ENTITYMANAGER_H

#include <unordered_map>
#include <cassert>
#include <stack>
#include "Entity.h"

class EntityManager {
public:

    EntityManager() {
        // Initialize the queue with all possible entity IDs
        for (Entity entity = 0; entity < ENGINE_MAX_ENTITIES; ++entity) {
            _freeEntities.push(entity);
        }
    }

    Entity createEntity() {
        assert(!_freeEntities.empty());
        Entity e = _freeEntities.top();
        _entities[e] = 0;
        _freeEntities.pop();
        return e;
    }

    void destroyEntity(Entity e) {
        _freeEntities.push(e);
        _entities.erase(e);
    }

    void setSignature(Entity e, Signature s) {
        _entities[e] |= s;
    }

    void removeSignature(Entity e, Signature s) {
        _entities[e] &= s.flip();
    }

    Signature getSignature(Entity e) {
        return _entities[e];
    }

private:
    std::stack<Entity> _freeEntities;
    std::unordered_map<Entity, Signature> _entities;
};

#endif //ENGINE_ENTITYMANAGER_H
