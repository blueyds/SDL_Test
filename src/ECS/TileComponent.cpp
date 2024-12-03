#include "TileComponent.hpp"
#include "Entity.hpp"
#include "SpriteComponent.hpp"
#include <TextureManager.hpp>

ECS::Tile::~Tile(){
  SDL_DestroyTexture(texture);
}

ECS::Tile::Tile(int srcX, int srcY, int xpos, int ypos, std::string path) {
  texture = TextureManager::LoadTexture(path);

  srcRect.x = srcX;
  srcRect.y = srcY;
  srcRect.h = srcRect.w = 32;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = destRect.h = 32;
  
}

void ECS::Tile::draw(){
  TextureManager::Draw(texture,srcRect,destRect);
}