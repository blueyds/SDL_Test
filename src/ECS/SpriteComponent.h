#ifndef SPRITE_COMPONENT_H_5674
#define SPRITE_COMPONENT_H_5674
#include "Components.h"
#include <SDL.h>

class SpriteComponent: public Component{
public:
	SpriteComponent() = default;
	SpriteComponent(const char* path){
		setTex(path);
	}
	void setTex(const char* path){
		texture = TextureManager::LoadTexture(path);
	}
	void init() override{
		position = &entity->getComponent<PositionCompnent>();
		srcRect.y = srcRecr.x = 0;
		srcRect.h = 32;
		srcRect.w = 32;
		destRect.h = srcRect.h * 2;
		destRect.w = srcRect.w * 2;
	}
	
	void update() override{
		destRect.x = position->x();
		destRect.y = position->y();
	}
	
	void draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}
private:
	PositionComponent *position;
	SDL_Texture *texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
};

#endif