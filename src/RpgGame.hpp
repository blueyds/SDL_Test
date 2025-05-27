#ifndef DCDE9B8D_7220_4DD6_A62E_B3B01AFEF19B
#define DCDE9B8D_7220_4DD6_A62E_B3B01AFEF19B

#include "ECS/Components.hpp"

class RpgGame : public Game {
public:
  RpgGame() {};
  ~RpgGame() {}
  void BuildScene() override;
  void render() override;
  void update() override;

  void processAction(int action);
  static void addTile(int id, int row, int column);

private:
  static ECS::Manager &manager;
  static ECS::Entity &s_player;
  ECS::MapTiledCSV *map;

  ECS::Entity &player;
  ECS::Entity &wall;
}

#endif // DCDE9B8D_7220_4DD6_A62E_B3B01AFEF19B
