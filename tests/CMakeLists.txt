add_executable(DigitTester DigitTester.cpp)
target_link_libraries(DigitTester src_stuff)
add_test(NAME Testing_GetDigit COMMAND DigitTester)
