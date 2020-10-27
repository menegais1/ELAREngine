//
// Created by menegais1 on 26/10/2020.
//

#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include <cstdint>
#include <bitset>

#define ENGINE_MAX_ENTITIES 5000
#define ENGINE_MAX_COMPONENTS 64
using Entity = std::uint64_t;
using Signature = std::bitset<ENGINE_MAX_COMPONENTS>;
using ComponentType = std::uint8_t;

#endif //ENGINE_ENTITY_H
