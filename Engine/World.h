//
// Created by Roberto on 10/28/20.
//

#ifndef ENGINE_WORLD_H
#define ENGINE_WORLD_H

#include "SystemManager.h"
#include "EntityManager.h"
#include "ComponentManager.h"

class World {
public:

    //System Manager Methods
    template<typename T>
    void registerSystem() {
        _systemManager.registerSystem<T>();
    }

    //Entity Manager Methods
    Entity createEntity() {
        return _entityManager.createEntity();
    }

    void destroyEntity(Entity e) {
        _entityManager.destroyEntity(e);
    }

    Signature getSignature(Entity e) {
        return _entityManager.getSignature(e);
    }

    //Component Manager Methods
    template<typename T>
    void registerComponent() {
        _componentManager.registerComponent<T>();
    }

    template<typename T>
    void addComponent(Entity e, T data) {
        _componentManager.addComponent(e, data);
        _entityManager.setSignature(e, _componentManager.getComponentSignature<T>());
    }

    template<typename T>
    void removeComponent(Entity e) {
        _entityManager.removeSignature(e, _componentManager.getComponentSignature<T>());
        _componentManager.removeComponent<T>(e);
    }

    template<typename First = void, typename... Args>
    Signature getComponentSignature() {
        return sizeof...(Args) == 0 ? _componentManager.getComponentSignature<First>() : _componentManager.getComponentSignature<First>() | getComponentSignature<Args...>();
    }

    template<typename... Args>
    std::vector<Entity> *queryAll() {
        Signature signature;
        signature = getComponentSignature<Args...>();
        auto *entities = new std::vector<Entity>();
        for (auto iterator : _entityManager.getEntitiesIterator()) {
            if ((signature & iterator.second) == signature) {
                entities->push_back(iterator.first);
            }
        }
        return entities;
    }

private:
    SystemManager _systemManager{};
    EntityManager _entityManager{};
    ComponentManager _componentManager{};
};

#endif //ENGINE_WORLD_H
