#include "ECS/Mapping/MapTiledCSV.hpp"
#include "ECS/Core/Manager.hpp"
#include "Utilities.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

ECS::MapTiledCSV::MapTiledCSV(ECS::Manager &manager) {
  this->manager = manager;
}
