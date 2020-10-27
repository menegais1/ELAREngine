//
// Created by menegais1 on 27/10/2020.
//

#ifndef ENGINE_COMPONENTPOOL_H
#define ENGINE_COMPONENTPOOL_H

#include <unordered_map>
#include <array>
#include <cassert>
#include "Entity.h"

class IComponentPool {
public:
    virtual void removeComponent(Entity e) = 0;
};

template<typename T>
class ComponentPool : public IComponentPool {
public:
    void addComponent(Entity e, T componentData) {
        _pool[_componentArraySize] = componentData;
        _entityToIdMap.insert({e, _componentArraySize});
        _idToEntityMap.insert({_componentArraySize, e});
        _componentArraySize++;
    }

    void removeComponent(Entity e) override {
        if (_entityToIdMap.find(e) == _entityToIdMap.end()) return;
        _pool[_entityToIdMap[e]] = _pool[_componentArraySize - 1];
        _idToEntityMap[_entityToIdMap[e]] = _idToEntityMap[_componentArraySize - 1];
        _componentArraySize = _componentArraySize - 1;
        _entityToIdMap.erase(e);
        _idToEntityMap.erase(_componentArraySize - 1);
    }

    T &getComponent(Entity e) {
        assert(_entityToIdMap.find(e) != _entityToIdMap.end());
        return _pool[_entityToIdMap[e]];
    }

private:
    int _componentArraySize = 0;
    std::array<T, ENGINE_MAX_ENTITIES> _pool;
    std::unordered_map<Entity, int> _entityToIdMap;
    std::unordered_map<int, Entity> _idToEntityMap;
};

#endif //ENGINE_COMPONENTPOOL_H
