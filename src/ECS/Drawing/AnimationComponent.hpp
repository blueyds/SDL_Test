#ifndef ANIMATION_COMPONENT_HPP_232194312
#define ANIMATION_COMPONENT_HPP_232194312

#include "ECS/Drawing/SpriteComponent.hpp"
#include "ECS/Drawing/TransformComponent.hpp"

namespace ECS {

class Animation : public Component {
private:
  Sprite *sprite;
  Transformable *transform;
  // index is row of the sprite sheet for this animation.
  // assumed that each row is one animation sequence
  int index = 0;
  // int frame = 0;
  int nFrames = 0;
  int speed = 300; // ms per frame
  bool playing = false;

public:
  Animation(int numFrames, int msPerFrame);
  void init() override;
  void update() override;
  void play(int mIndex);
  void play(int mIndex, int numFrames, int msPerFrame);
  void stop();
};

} // namespace ECS

#endif