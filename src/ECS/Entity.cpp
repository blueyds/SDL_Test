#include "Entity.hpp"
#include "Manager.hpp"

ECS::Entity::Entity(ECS::Manager &mManager) { manager = &mManager; }

void ECS::Entity::addGroup(ECS::Group mGroup) {
  groupBitset[mGroup] = true;
  manager->AddToGroup(this, mGroup);
}

void ECS::Entity::update() {
  for (auto &c : components)
    c->update();
}

void ECS::Entity::draw() {
  for (auto &c : components)
    c->draw();
}

bool ECS::Entity::isActive() const { return active; }

void ECS::Entity::destroy() { active = false; }

bool ECS::Entity::hasGroup(ECS::Group mGroup) { return groupBitset[mGroup]; }

void ECS::Entity::delGroup(ECS::Group mGroup) { groupBitset[mGroup] = false; }
