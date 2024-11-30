#ifndef TILE_COMPONENT_HPP_83478392
#define TILE_COMPONENT_HPP_83478392

#include <SDL.h>
#include "ECS.hpp"
#include "TransformCompnent.hpp"
#include "SpriteComponent.hpp"

namespace ECS{

class Tile: public Component {
public:
	Transformable * transform;
	Sprite *sprite;
	SDL_Rect tileRect;
	int tileID;
	char* path;
	Tile() = default;
	
	Tile(int x, int y, int w, int h, int id){
		tileRect.x  = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;
		switch (tileID){
		case 0:
			path = "water.png";
			break;
		case 1: 
			path = "dirt.png"
			break;
		case 2:
			path = "grass.png"
			break;
		default:
			break;
		}
	}
	
	void init() override{
		float x = static_cast<float>(tileRect.x);
		float y = static_cast<float>(tileRect.y)
		entity->addComponent<ECS::Transformable>(x, y, tileRect.w, tileRect.h, 1);
		transform = &entity->getComponent<ECS::Transformable>();
		entity->addComponent<ECS::Sprite>(path);
		sprite = &entity->getComponent<ECS::Sprite>();
	}
};
	
	
}


#endif