cmake_minimum_required(VERSION 3.16.5)
project(Engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(Engine main.cpp Entity.h ComponentManager.h ComponentPool.h EntityManager.h System.h SystemManager.h World.h)