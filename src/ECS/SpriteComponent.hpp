#ifndef SPRITE_COMPONENT_H_5674
#define SPRITE_COMPONENT_H_5674

#include "TransformComponent.hpp"
#include <SDL2/SDL.h>
#include <string>

namespace ECS {
class Sprite : public Component {
public:
  Sprite() = default;

  Sprite(std::string path);

  ~Sprite();

  void setTex(std::string path);

  void setSrcRectPos(int x, int y);

  void init() override;

  void update() override;

  void draw() override;

private:
  ECS::Transformable *transform;
  SDL_Texture *texture;
  SDL_Rect srcRect;
  SDL_Rect destRect;
};
} // namespace ECS
  // namespace ECS
#endif