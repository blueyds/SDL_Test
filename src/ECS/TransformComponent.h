#ifndef TRANSFORM_COMPONENT_HPP_1234351223
#define TRANSFORM_COMPONENT_HPP_1234351223

#include <Vector2D.h>
#include "ECS.h"

class TransformComponent : public Component {
public:
	Vector2D position;
	Vector2D velocity;
	
	int speed = 3;
	
	TransformComponent() { position = Vector2D(); }
	
	TransformComponent(float x, float y) { position = Vector2D(x, y); }
	
	void init() override {
		velocity.x = 0;
		velocity.y = 0;
	}
	
	void update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};

#endif