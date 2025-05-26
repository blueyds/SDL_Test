#include "player.hpp"
#include "ECS/Components.hpp"
#include "game.hpp"

void Player::init() {
  addComponent<ECS::Transformable>(0, 0, 64, 48, 1);
  addComponent<ECS::Sprite>(
      std::string("universal-lpc-sprite_male_01_walk-3frame.png"));
  addComponent<ECS::Animation>(3, 500);
  addComponent<ECS::Keyboard>(&Game::event);
  ECS::Collider &c = addComponent<ECS::Collider>(std::string("player"));
  ECS::Entity *e = this;

  c.changeTestEntity(e);
  addGroup(Game::groupPlayers);
}