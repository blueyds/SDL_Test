#ifndef ECS_HPP_723864387
#define ECS_HPP_723864387
#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

namespace ECS {

class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID getNewComponentTypeID() {
  static ComponentID lastID = 0u;
  return lastID++;
}

// this way all types of Position will return 1 and all types of x will return 2
// etc
template <typename t> inline ComponentID getComponentTypeID() noexcept {
  static ComponentID typeID = getNewComponentTypeID();
  return typeID;
}

constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using GroupBitSet = std::bitset<maxGroups>;
using ComponentArray = std::array<Component *, maxComponents>;

class Component {
public:
  Entity *entity;

  virtual void init() {}
  virtual void update() {}
  virtual void draw() {}

  virtual ~Component() {}
};

class Entity {
public:
  Entity(Manager &mManager) : manager(mManager) {}

  void update() {
    for (auto &c : components)
      c->update();
  }
  void draw() {
    for (auto &c : components)
      c->draw();
  }

  bool isActive() const { return active; }

  void destroy() { active = false; }

  bool hasGroup(Group mGroup) { return groupBitset[mGroup]; }
  void addGroup(Group mGroup);

  void delGroup(Group mGroup) { groupBitset[mGroup] = false; }

  template <typename T> bool hasComponent() {
    return componentBitset[getComponentTypeID<T>()];
  }

  template <typename T, typename... TArgs> T &addComponent(TArgs &&...mArgs) {
    T *c(new T(std::forward<TArgs>(mArgs)...));
    c->entity = this;
    std::unique_ptr<Component> u_ptr(c);
    components.emplace_back(std::move(u_ptr));
    componentArray[getComponentTypeID<T>()] = c;
    componentBitset[getComponentTypeID<T>()] = true;
    c->init();
    return *c;
  }

  template <typename T> T &getComponent() const {
    auto ptr(componentArray[getComponentTypeID<T>()]);
    return *static_cast<T *>(ptr);
  }

private:
  bool active = true;
  Manager &manager;
  std::vector<std::unique_ptr<Component>> components;

  ComponentArray componentArray;
  ComponentBitSet componentBitset;
  GroupBitSet groupBitset;
};

class Manager {
public:
  void update() {
    for (auto &e : entities)
      e->update();
  }
  void draw() {
    for (auto &e : entities)
      e->draw();
  }
  // TODO go through and remove inactive entities
  void refresh() {

    for (auto i(0u); i < maxGroups; i++) {
      auto &v(groupedEntities[i]);
      v.erase(std::remove_if(std::begin(v), std::end(v),
                             [i](Entity *mEntity) {
                               return !mEntity->isActive() ||
                                      !mEntity->hasGroup(i);
                             }),
              std::end(v));
    }

    entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                                  [](const std::unique_ptr<Entity> &mEntity) {
                                    return !mEntity->isActive();
                                  }),
                   std::end(entities));
  }

  void AddToGroup(Entity *mEntity, Group mGroup) {
    groupedEntities[mGroup].emplace_back(mEntity);
  }

  std::vector<Entity *> &getGroup(Group mGroup) {
    return groupedEntities[mGroup];
  }

  void drawGroup(Group mGroup) {
    auto &v(getGroup(mGroup));
    for (auto &item : v) {
      item->draw();
    }
  }

  Entity &addEntity() {
    Entity *e = new Entity(*this);
    std::unique_ptr<Entity> uPtr(e);
    entities.emplace_back(std::move(uPtr));
    return *e;
  }

private:
  std::vector<std::unique_ptr<Entity>> entities;
  std::array<std::vector<Entity *>, maxGroups> groupedEntities;
};
} // namespace ECS
#endif