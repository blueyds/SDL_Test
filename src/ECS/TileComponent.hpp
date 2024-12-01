#ifndef TILE_COMPONENT_HPP_83478392
#define TILE_COMPONENT_HPP_83478392

#include "TransformComponent.hpp"
#include <SDL.h>
#include <string>

namespace ECS {
class Sprite;

class Entity;

class Tile : public Component {
public:
  Transformable *transform;
  Sprite *sprite;
  SDL_Rect tileRect;
  int tileID;
  std::string path;
  Tile() = default;

  Tile(int x, int y, int w, int h, int id);

  void init() override;
};

} // namespace ECS

#endif