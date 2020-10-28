#include <iostream>
#include "ComponentManager.h"
#include "EntityManager.h"
#include "System.h"
#include "SystemManager.h"

struct Point {
    float x, y;

    Point(float x, float y) : x(x), y(y) {}

    Point() = default;
};

struct Rotation {
    float pitch, yaw, roll;

    Rotation(float pitch, float yaw, float roll) : pitch(pitch), yaw(yaw), roll(roll) {}

    Rotation() = default;
};

struct RotationSystem : System {
    void update() override
    {
        for (auto const& entity : entities)
        {

        }
    }
};


int main() {
    ComponentManager componentManager;
    EntityManager entityManager;
    SystemManager systemManager;

    componentManager.registerComponent<Point>();
    componentManager.registerComponent<Rotation>();
    Entity e = entityManager.createEntity();
    Entity e1 = entityManager.createEntity();
    componentManager.addComponent(e, Point(3, 1));
    componentManager.addComponent(e, Rotation(10, 20, 30));
    entityManager.setSignature(e, componentManager.getComponentSignature<Point>());
    entityManager.setSignature(e, componentManager.getComponentSignature<Rotation>());
    systemManager.addSystem<RotationSystem>();

    Signature s = entityManager.getSignature(e);
    std::cout << s << std::endl;
    componentManager.addComponent(e1, Point(4, 5));
    entityManager.setSignature(e1, componentManager.getComponentSignature<Point>());
    std::cout << componentManager.getComponent<Rotation>(e).yaw << std::endl;
    componentManager.removeComponent<Point>(e);
    entityManager.removeSignature(e, componentManager.getComponentSignature<Point>());
    s = entityManager.getSignature(e1);
    std::cout << s << std::endl;
    std::cout << componentManager.getComponent<Point>(e1).y << std::endl;
    componentManager.getComponent<Point>(e1).x = 10;
    std::cout << componentManager.getComponent<Point>(e1).x << std::endl;
    return 0;
}
