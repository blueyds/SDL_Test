#include "TileComponent.hpp"
#include "Entity.hpp"
#include "SpriteComponent.hpp"
#include "TransformComponent.hpp"
#include <TextureManager.hpp>
#include <Vector2D.hpp>

ECS::Tile::~Tile(){
  SDL_DestroyTexture(texture);
}

ECS::Tile::Tile(int srcX, int srcY, int xpos, int ypos, std::string path,ECS::Transformable* playerTrans) {
  playerTransform = playerTrans;
  texture = TextureManager::LoadTexture(path);

  srcRect.x = srcX;
  srcRect.y = srcY;
  srcRect.h = srcRect.w = 32;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = destRect.h = 32;
  
}

void ECS::Tile::update(){
  destRect.x += -(playerTransform->velocity.x);
  destRect.y += -(playerTransform->velocity.y);
}

void ECS::Tile::draw(){
  TextureManager::Draw(texture,srcRect,destRect);
}