#ifndef MAP_H_12532
#define MAP_H_12532
#include "Core/Manager.hpp"
#include "Utilities.hpp"
#include "./../RpgGame.hpp"
#include <string>
#include <fstream>

namespace ECS {
class MapTiledCSV {
private:
  ECS::Manager &manager;

public:
  MapTiledCSV(ECS::Manager &ref_manager): manager(ref_manager){};
  ~MapTiledCSV();
  void loadMap(std::string path, int sizeX, int sizeY);
};
}; // namespace ECS
#endif