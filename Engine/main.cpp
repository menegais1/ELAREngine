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

struct Rotation {
    float pitch, yaw, roll;

    Rotation(float pitch, float yaw, float roll) : pitch(pitch), yaw(yaw), roll(roll) {}

    Rotation() = default;
};

struct RotationSystem : System {
    void update() override {
        
    }
};


int main() {

    World world;
    world.registerComponent<Point>();
    world.registerComponent<Rotation>();
    Entity e = world.createEntity();
    Entity e1 = world.createEntity();
    world.addComponent(e, Point(3, 1));
    world.addComponent(e, Rotation(10, 20, 30));


    world.addComponent(e1, Rotation(10, 10, 5));

    world.registerSystem<RotationSystem>();
    auto entities = world.queryAll<Point>();

    for (auto e : *entities) {
        std::cout << world.getSignature(e) << std::endl;
    }
    return 0;
}
