#ifndef ECS_MANAGER_HPP_343291278
#define ECS_MANAGER_HPP_343291278
#include "ECS/Core/Entity.hpp"
#include <array>
#include <vector>

namespace ECS {

class Manager {
public:
  void update();
  void draw();
  void refresh();
  void AddToGroup(Entity *mEntity, Group mGroup);
  std::vector<Entity *> &getGroup(Group mGroup);
  void drawGroup(Group mGroup);
  Entity &addEntity();
  template <typename T, typename... TArgs> T &addEntity(TArgs &&...mArgs) {
    ECS::Entity::manager = this;
    T *e(new T(std::forward<TArgs>(mArgs)...));
    std::unique_ptr<Entity> uPtr(e);
    uPtr->init();
    entities.emplace_back(std::move(uPtr));
    return *e;
  }

private:
  std::vector<std::unique_ptr<Entity>> entities;
  std::array<std::vector<Entity *>, maxGroups> groupedEntities;
};

} // namespace ECS
#endif