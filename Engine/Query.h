//
// Created by Lorenzo on 10/28/12020.
//

#ifndef ENGINE_QUERY_H
#define ENGINE_QUERY_H


class Query
{

public:

    Query(ComponentManager& _componentManager, EntityManager& entityManager) : componentsManager(_componentManager), entitiesManager(entityManager)
    {

    }



private:
    const ComponentManager& componentsManager;
    const EntityManager& entitiesManager;
};
#endif //ENGINE_QUERY_H
