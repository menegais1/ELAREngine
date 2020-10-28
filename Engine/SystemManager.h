#pragma once

#include "Entity.h"

class SystemManager {

public:

    template <typename T>
    std::shared_ptr<T> addSystem()
    {
        static_assert(std::is_base_of<System, T>::value, "Type is not a system");
        const char* typeName = typeid(T).name();
        assert(systems.find(typeName) == systems.end() && "System is already registered!");
        auto system = std::make_shared<T>();
        systems.insert({typeName, system});
        return system;
    }

    void EntityDestroyed(Entity entity)
    {
        for (auto const& pair : systems)
        {
            auto const& system = pair.second;

            system->entities.erase(entity);
        }
    }

    void EntitySignatureDestroyed(Entity entity, Signature entitySignature)
    {
        for (auto const& tuple : systems)
        {
            auto const& type = tuple.first;
            auto const& system = tuple.second;
            auto const& systemSignature = system->signature;

            if ((entitySignature & systemSignature) == systemSignature)
            {
                system->entities.insert(entity);
            }
            else
            {
                system->entities.erase(entity);
            }
        }
    }

private:
    std::unordered_map<const char*, std::shared_ptr<System>> systems{};
};