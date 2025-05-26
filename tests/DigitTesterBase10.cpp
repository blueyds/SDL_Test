#include "Utilities.hpp"
#include <cassert>

int DigitTesterBase10(int argc, char **argv) {
  assert(Utilities::getBase10Digits(156, 0)[1] == 5);
  assert(Utilities::getBase10Digits(4831, 0)[3] == 1);
  assert(Utilities::getBase10Digits(156, 0)[0] == 1);
  assert(Utilities::getBase10Digits(156, 0)[2] == 6);
  assert(Utilities::getBase10Digits(4, 2)[1] = 4);
  return 0;
};