#ifndef ECS_HPP_723864387
#define ECS_HPP_723864387
#include <array>
#include <bitset>
#include <memory>
#include <vector>

namespace ECS {

class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;

inline ComponentID getNewComponentTypeID() {
  static ComponentID lastID = 0u;
  return lastID++;
}

// this way all types of Position will return 1 and all types of x will return 2
// etc
template <typename t> inline ComponentID getComponentTypeID() noexcept {
  static ComponentID typeID = getNewComponentTypeID();
  return typeID;
}


class Component {
public:
  Entity *entity;

  virtual void init() {}
  virtual void update() {}
  virtual void draw() {}

  virtual ~Component() {}
};


} // namespace ECS
#endif