#include "AnimationComponent.hpp"
#include "Entity.hpp"
#include <Utilities.hpp>

ECS::Animation::Animation(int numFrames, int msPerFrame) {
  nFrames = numFrames;
  speed = msPerFrame;
}

void ECS::Animation::init() {
  sprite = &entity->getComponent<ECS::Sprite>();
  transform = &entity->getComponent<ECS::Transformable>();
}

void ECS::Animation::update() {
  if (playing) {
    int x = static_cast<int>(transform->width *
                             (Utilities::getTicks() / speed % nFrames));
    int y = index * transform->height;
    sprite->setSrcRectPos(x, y);
  }
}

void ECS::Animation::play(int mIndex) {
  playing = true;
  index = mIndex;
}

void ECS::Animation::play(int mIndex, int numFrames, int msPerFrame) {
  playing = true;
  index = mIndex;
  nFrames = numFrames;
  speed = msPerFrame;
}

void ECS::Animation::stop() { playing = false; }