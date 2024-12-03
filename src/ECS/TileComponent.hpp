#ifndef TILE_COMPONENT_HPP_83478392
#define TILE_COMPONENT_HPP_83478392

#include "Component.hpp"
#include <SDL2/SDL.h>

namespace ECS {
class Sprite;

class Entity;
class Transformable;

class Tile : public Component {
public:
  SDL_Texture *texture;
  SDL_Rect srcRect, destRect;
  Transformable* playerTransform;
  Tile() = default;

  ~Tile();

  Tile(int srcX, int srcY, int xpos, int ypos, std::string path, Transformable *playerTransform);

  void update() override;
  void draw() override;

};

} // namespace ECS

#endif