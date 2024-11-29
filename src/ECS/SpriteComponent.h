#ifndef SPRITE_COMPONENT_H_5674
#define SPRITE_COMPONENT_H_5674
#include "ECS.h"
#include <SDL.h>
#include <TextureManager.hpp>

namespace ECS {
class Sprite : public Component {
public:
  Sprite() = default;
  Sprite(const char *path) { setTex(path); }

  ~Sprite() { SDL_DestroyTexture(texture); }

  void setTex(const char *path) { texture = TextureManager::LoadTexture(path); }

  void init() override {
    transform = &entity->getComponent<ECS::Transformable>();
    srcRect.y = srcRect.x = 0;
    srcRect.h = transform->height;
    srcRect.w = transform->width;
    destRect.h = transform->scaledHeight();
    destRect.w = transform->scaledWidth();
  }

  void update() override {
    destRect.x = static_cast<int>(transform->position.x);
    destRect.y = static_cast<int>(transform->position.y);
    destRect.h = transform->scaledHeight();
    destRect.w = transform->scaledWidth();
  }

  void draw() override { TextureManager::Draw(texture, srcRect, destRect); }

private:
  ECS::Transformable *transform;
  SDL_Texture *texture;
  SDL_Rect srcRect;
  SDL_Rect destRect;
};
} // namespace ECS
  // namespace ECS
#endif