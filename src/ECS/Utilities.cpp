#include "Utilities.hpp"
#include <chrono>

uint64_t Utilities::getTicks() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch())
      .count();
}

int Utilities::getDigit(std::string inChar) {
  if (inChar == "0") {
    return 0;
  } else if (inChar == "1") {
    return 1;
  } else if (inChar == "2") {
    return 2;
  } else if (inChar == "3") {
    return 3;
  } else if (inChar == "4") {
    return 4;
  } else if (inChar == "5") {
    return 5;
  } else if (inChar == "6") {
    return 6;
  } else if (inChar == "7") {
    return 7;
  } else if (inChar == "8") {
    return 8;
  } else if (inChar == "9") {
    return 9;
  } else {
    return -1;
  }
}

std::vector<int> Utilities::getBase10Digits(int input, int numDigits) {
  std::vector<int> result;
  int runningInput = input;
  while (runningInput > 0) {
    int digit = runningInput % 10;
    runningInput /= 10;
    result.emplace(result.begin(), digit);
  }
  // if numDigits is 0 then no padding is looked at
  // otherwise we will pad the front based on numbdigits
  if (numDigits != 0) {
    while (result.size() < numDigits) {
      result.emplace(result.begin(), 0);
    }
  }

  return result;
}