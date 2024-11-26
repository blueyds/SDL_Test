#ifndef TRANSFORM_COMPONENT_HPP_1234351223
#define TRANSFORM_COMPONENT_HPP_1234351223

#include <Vector2D.h>

class TransformComponent: public Component{
public:
	Vector2D position;
	
	TransformComponent(){
		position = Vector2D();
	}
	TransformComponent(float x, float y){
		position = Vector2D(x,y);
	}
	
	void update() override {
		xpos++;
		ypos++;
	}
	
};

#endif