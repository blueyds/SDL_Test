#ifndef TILE_COMPONENT_HPP_83478392
#define TILE_COMPONENT_HPP_83478392

#include "ECS/Core/Component.hpp"
#include <SDL2/SDL.h>

namespace ECS {
class Sprite;

class Entity;
class Transformable;

class TextureTileInfo {
public:
  int x;
  int y;
  int tileSize;
  std::string file_name;
  TextureTileInfo(std::string fName, int srcX, int srcY, int tileSize);
};

class GameTileInfo {
public:
  int x;
  int y;
  int tileSize;
  GameTileInfo(int destX, int destY, int tileSize);
};

class Tile : public Component {
public:
  SDL_Texture *texture;
  SDL_Rect srcRect, destRect;
  Transformable *playerTransform;
  Tile() = default;

  ~Tile();

  Tile(TextureTileInfo textureInfo, GameTileInfo gameTileInfo,
       Transformable *playerTransform);

  void update() override;
  void draw() override;
};

} // namespace ECS

#endif