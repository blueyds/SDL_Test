#ifndef ECS_MANAGER_HPP_343291278
#define ECS_MANAGER_HPP_343291278
#include <array>
#include <vector>
#include "Entity.hpp"

namespace ECS{

class Manager {
public:
	void update();
	void draw();
	void refresh();
	void AddToGroup(Entity *mEntity, Group mGroup);
	std::vector<Entity *> &getGroup(Group mGroup);
	void drawGroup(Group mGroup);
	Entity &addEntity();
	
private:
	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity *>, maxGroups> groupedEntities;
};

}
#endif