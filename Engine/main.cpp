#include <iostream>
#include "ComponentManager.h"
#include "EntityManager.h"
#include "System.h"
#include "SystemManager.h"
#include "World.h"

struct Point {
    float x, y;

    Point(float x, float y) : x(x), y(y) {}

    Point() = default;
};

struct Velocity {
    float x, y;

    Velocity(float x, float y) : x(x), y(y) {}

    Velocity() = default;
};

struct Rotation {
    float pitch, yaw, roll;

    Rotation(float pitch, float yaw, float roll) : pitch(pitch), yaw(yaw), roll(roll) {}

    Rotation() = default;
};

struct VelocitySystem : System {
    void update(World& world) override {
        for (auto e : *world.queryAll<Point, Velocity>())
        {
            auto& velocity = world.getComponent<Velocity>(e);
            auto& point = world.getComponent<Point>(e);

            point.x += velocity.x;
            point.y += velocity.y;

            std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
        }
    }
};


int main() {

    World world;
    world.registerSystem<VelocitySystem>();

    Entity e = world.createEntity();
    Entity e1 = world.createEntity();

    world.registerComponent<Point>();
    world.registerComponent<Rotation>();
    world.registerComponent<Velocity>();

    world.addComponent(e, Point(3, 1));
    world.addComponent(e, Velocity(10, 7));
    world.addComponent(e, Rotation(10, 20, 30));
    world.addComponent(e1, Rotation(10, 10, 5));

    world.updateSystems();
    world.updateSystems();
    world.updateSystems();

    return 0;
}
