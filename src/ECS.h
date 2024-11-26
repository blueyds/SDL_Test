#ifndef ECS_HPP_723864387
#define ECS_HPP_723864387
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;`

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID(){
	static ComponentID lastID = 0;
	return lastID++;
}

// this way all types of Position will return 1 and all types of x will return 2 etc
template <typeName t> 
inline ComponentID getComponentTypeID() noexcept {
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component{
public:
	Entity* entity;
	
	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}
	
	virtual ~Component() {}
};

class Entity{
public:
	void update(){
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}
	void draw(){ }
	
	bool isActive() const { return isActive; }
	
	void destroy() { isActive = false; }
	
	template<typename T> 
	bool hasComponent() const{
		return componentBitSet[getComponentTypeID<T>]()
	} 
	
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs){
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> u_ptr( c );
		components.emplace_back( std::move(u_ptr));
		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] =  true;
		c->init();
		return c;
	}
		
	template <typename T>
	T& getComponent() const{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;
	
	ComponentArray componentArray;
	ComponentBitSet componentBitset;
};

class Manager{
public:
	void update(){
		for (auto& e : entities) e->update();
	}
	void draw(){
		for (auto&e : entities) e->draw();
	}
	// TODO go through and remove inactive entities 
	void refresh(){
		entities.erase(std::remove_if(std::begin(entities), std::end(entities)))
	}
	Entity& addEntity(){
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr( e );
		entities.emplace_back(std::move(uPtr));
		return *e;
	}
private:
	std::vector<std::unique_ptr<Entity>> entities;
	
	
};


#endif