//
// Created by menegais1 on 27/10/2020.
//

#ifndef ENGINE_COMPONENTMANAGER_H
#define ENGINE_COMPONENTMANAGER_H

#include <typeinfo>
#include <iostream>
#include <unordered_map>
#include <array>
#include "ComponentPool.h"
#include "Entity.h"

class ComponentManager {
public:
    template<typename T>
    void registerComponent() {
        const char *type = typeid(T).name();
        _componentsHash.insert({type, new ComponentPool<T>()});
        _componentTypes.insert({type, _curComponentType++});
    }

    template<typename T>
    void addComponent(Entity e, T data) {
        ComponentPool<T> *componentPool = getComponentPool<T>();
        componentPool->addComponent(e, data);
    }

    template<typename T>
    void removeComponent(Entity e) {
        ComponentPool<T> *componentPool = getComponentPool<T>();
        componentPool->removeComponent(e);
    }

    template<typename T>
    T &getComponent(Entity e) {
        ComponentPool<T> *componentPool = getComponentPool<T>();
        return componentPool->getComponent(e);
    }

    template<typename T>
    Signature getComponentSignature() {
        return Signature(_componentTypes[typeid(T).name()]);
    }

private:
    //This is a hash map storing a ComponentType and a component pool
    std::unordered_map<const char *, IComponentPool *> _componentsHash;
    std::unordered_map<const char *, ComponentType> _componentTypes;
    ComponentType _curComponentType = 1;

    template<typename T>
    ComponentPool<T> *getComponentPool() {
        const char *type = typeid(T).name();
        return static_cast<ComponentPool<T> *>(_componentsHash[type]);
    }

};

#endif //ENGINE_COMPONENTMANAGER_H
