#ifndef SPRITE_COMPONENT_H_5674
#define SPRITE_COMPONENT_H_5674
#include <TextureManager.hpp>
#include "ECS.h"
#include <SDL.h>

class SpriteComponent : public Component {
public:
	SpriteComponent() = default;
	SpriteComponent(const char *path) { setTex(path); }
	
	~SpriteComponent(){
		SDL_DestroyTexture(texture);
	}
	
	void setTex(const char *path) { texture = TextureManager::LoadTexture(path); }
	
	void init() override {
		transform = &entity->getComponent<TransformComponent>();
		srcRect.y = srcRect.x = 0;
		srcRect.h = transform.height;
		srcRect.w = transform.width;
		destRect.h = transform.scaledHeight();
		destRect.w = transform.scaledWidth();
	}

	void update() override {
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
	}

	void draw() override { TextureManager::Draw(texture, srcRect, destRect); }

private:
	TransformComponent *transform;
	SDL_Texture *texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
};

#endif