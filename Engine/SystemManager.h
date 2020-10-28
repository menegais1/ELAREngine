#ifndef ENGINE_SYSTEM_MANAGER_H
#define ENGINE_SYSTEM_MANAGER_H

#include <vector>
#include "Entity.h"
#include "System.h"

class SystemManager {
public:

    template<typename T>
    void registerSystem() {
        static_assert(std::is_base_of<System, T>::value, "Type is not a system");
        const char *typeName = typeid(T).name();
        assert(_systems.find(typeName) == _systems.end() && "System is already registered!");
        T *system = new T();
        _systems.insert({typeName, system});
        _activeSystems.push_back(system);
    }

//Todo Commented code due to System not containing any entity info, world is responsible for returning a list containing all pertinent info using a query
//    //Todo This must be delayed until the frame ends, or else it can crash the system
//    void EntityDestroyed(Entity entity) {
//        for (auto const &pair : _systems) {
//            auto const &system = pair.second;
//            system->entities.erase(entity);
//        }
//    }
//
//    //Todo This must be delayed until the frame ends, or else it can crash the system
//    void EntitySignatureDestroyed(Entity entity, Signature entitySignature) {
//        for (auto const &tuple : _systems) {
//            auto const &type = tuple.first;
//            auto const &system = tuple.second;
//            auto const &systemSignature = system->signature;
//
//            if ((entitySignature & systemSignature) == systemSignature) {
//                system->entities.insert(entity);
//            } else {
//                system->entities.erase(entity);
//            }
//        }
//    }

private:
    std::unordered_map<const char *, System *> _systems;
    std::vector<System *> _activeSystems;
};

#endif