#include "ECS.hpp"

void ECS::Entity::addGroup(ECS::Group mGroup) {
  groupBitset[mGroup] = true;
  manager.AddToGroup(this, mGroup);
}