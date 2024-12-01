#ifndef ENTITY_HPP_3732191
#define ENTITY_HPP_3732191
#include "Component.hpp"
#include <array>
#include <bitset>
#include <vector>

namespace ECS {
class Manager;

using Group = std::size_t;

constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

using GroupBitSet = std::bitset<maxGroups>;
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component *, maxComponents>;

class Entity {
public:
  Entity(Manager &mManager);

  void update();

  void draw();

  bool isActive() const;

  void destroy();

  bool hasGroup(Group mGroup);
  void addGroup(Group mGroup);

  void delGroup(Group mGroup);

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
  Manager *manager;
  std::vector<std::unique_ptr<Component>> components;

  ComponentArray componentArray;
  ComponentBitSet componentBitset;
  GroupBitSet groupBitset;
};
} // namespace ECS
#endif