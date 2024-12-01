#include <TextureManager.hpp>
#include "SpriteComponent.hpp"

ECS::Sprite::Sprite(std::string path) { 
	setTex(path); 
}

ECS::Sprite::~Sprite() { 
	SDL_DestroyTexture(texture); 
}

void ECS::Sprite::setTex(std::string path) { 
	texture = TextureManager::LoadTexture(path); 
}

void ECS::Sprite::setSrcRectPos(int x, int y){
	srcRect.x = x;
	srcRect.y = y;
}

void ECS::Sprite::init() {
	transform = &entity->getComponent<ECS::Transformable>();
	srcRect.y = srcRect.x = 0;
	srcRect.h = transform->height;
	srcRect.w = transform->width;
	destRect.h = transform->scaledHeight();
	destRect.w = transform->scaledWidth();
}

void ECS::Sprite::update() {
	destRect.x = static_cast<int>(transform->position.x);
	destRect.y = static_cast<int>(transform->position.y);
	destRect.h = transform->scaledHeight();
	destRect.w = transform->scaledWidth();
}

void ECS::Sprite::draw() { 
	TextureManager::Draw(texture, srcRect, destRect); 
}