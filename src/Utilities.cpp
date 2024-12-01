#include "Utilities.hpp"
#include <chrono>

uint64_t Utilities::getTicks() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch())
      .count();
}