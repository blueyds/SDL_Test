#include "TileComponent.hpp"
#include "Entity.hpp"
#include "SpriteComponent.hpp"
#include "TransformComponent.hpp"
#include <TextureManager.hpp>
#include <Vector2D.hpp>

ECS::Tile::~Tile(){
  SDL_DestroyTexture(texture);
};

ECS::TextureTileInfo::TextureTileInfo(std::string fName, int srcX, int srcY, int tileSize ){
  this->file_name = fName;
  this->x = srcX;
  this->y = srcY;
  this->tileSize = tileSize;
}

ECS::GameTileInfo::GameTileInfo(int destX, int destY, int tileSize){
  this->tileSize = tileSize;
  this->x = destX;
  this->y = destY;
}

ECS::Tile::Tile(TextureTileInfo textureInfo, GameTileInfo gameTileInfo, ECS::Transformable* playerTrans) {
  playerTransform = playerTrans;
  texture = TextureManager::LoadTexture(textureInfo.file_name);

  srcRect.x = textureInfo.x;
  srcRect.y = textureInfo.y;
  srcRect.h = srcRect.w = textureInfo.tileSize;

  destRect.x = gameTileInfo.x;
  destRect.y = gameTileInfo.y;
  destRect.w = destRect.h = gameTileInfo.tileSize;
  
}

void ECS::Tile::update(){
  destRect.x += -(playerTransform->velocity.x);
  destRect.y += -(playerTransform->velocity.y);
}

void ECS::Tile::draw(){
  TextureManager::Draw(texture,srcRect,destRect);
}