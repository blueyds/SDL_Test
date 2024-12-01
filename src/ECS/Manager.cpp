#include <vector>
#include <algorithm>
#include <memory>
#include "Manager.hpp"

void ECS::Manager::update() {
	for (auto &e : entities)
	e->update();
}

void ECS::Manager::draw() {
	for (auto &e : entities)
		e->draw();
}

// TODO go through and remove inactive entities
void ECS::Manager::refresh() {
	for (auto i(0u); i < maxGroups; i++) {
		auto &v(groupedEntities[i]);
		v.erase(std::remove_if(std::begin(v), std::end(v),[i](Entity *mEntity) {
			return !mEntity->isActive() || !mEntity->hasGroup(i);}),
			std::end(v));}
	entities.erase(std::remove_if(std::begin(entities), std::end(entities),[](const std::unique_ptr<Entity> &mEntity) {
		return !mEntity->isActive();}),
		std::end(entities));
}

void ECS::Manager::AddToGroup(Entity *mEntity, Group mGroup) {
	groupedEntities[mGroup].emplace_back(mEntity);
}

std::vector<Entity *>& ECS::Manager::getGroup(Group mGroup) {
	return groupedEntities[mGroup];
}

void ECS::Manager::drawGroup(Group mGroup) {
	auto &v(getGroup(mGroup));
	for (auto &item : v) {
		item->draw();
	}
}

Entity& ECS::Manager::addEntity() {
	Entity *e = new Entity(*this);
	std::unique_ptr<Entity> uPtr(e);
	entities.emplace_back(std::move(uPtr));
	return *e;
}
