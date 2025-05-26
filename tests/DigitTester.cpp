#include "Utilities.hpp"
#include <cassert>

int main(int argc, char** argv){
    assert(Utilities::getDigit("0") == 0);
    assert(Utilities::getDigit("1") == 1);
    assert(Utilities::getDigit("2") == 2);
    assert(Utilities::getDigit("3") == 3);
    assert(Utilities::getDigit("4") == 4);
    assert(Utilities::getDigit("5") == 5);
    assert(Utilities::getDigit("6") == 6);
    assert(Utilities::getDigit("7") == 7);
    assert(Utilities::getDigit("8") == 8);
    assert(Utilities::getDigit("9") == 9);
    assert(Utilities::getDigit("12") == -1);
    assert(Utilities::getDigit("-3") == -1);      
    return 0;
};