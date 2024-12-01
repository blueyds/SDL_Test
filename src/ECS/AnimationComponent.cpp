#include "AnimationComponent.hpp"
#include "Entity.hpp"
#include <Utilities.hpp>

void ECS::Animation::init() {
  sprite = &entity->getComponent<ECS::Sprite>();
  transform = &entity->getComponent<ECS::Transformable>();
}

void ECS::Animation::update() {
  if (playing) {
    int x = static_cast<int>(Utilities::getTicks() / speed % nFrames);
    int y = index * transform->height;
    sprite->setSrcRectPos(x, y);
  }
}

void ECS::Animation::play(int mIndex) {
  playing = true;
  index = mIndex;
}

void ECS::Animation::stop() { playing = false; }