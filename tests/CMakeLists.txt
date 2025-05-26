create_test_sourcelist(TestsToRun TestCxx.cpp 
        DigitTester.cpp 
        DigitTesterBase10.cpp 
)
add_executable(TestCxx ${TestsToRun})
target_link_libraries(TestCxx src_stuff)
add_test(NAME Utilities.GetDigits COMMAND TestCxx DigitTester)
add_test(NAME Utilities.GetBase10 COMMAND TestCxx DigitTesterBase10)