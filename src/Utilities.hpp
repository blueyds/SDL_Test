#include <cstdint>
#include <string>
#include <vector>
namespace Utilities {

uint64_t getTicks();

int getDigit(std::string inChar);

std::vector<int> getBase10Digits(int input, int numDigits);

} // namespace Utilities
