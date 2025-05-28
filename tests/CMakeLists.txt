create_test_sourcelist(TestsToRun TestCxx.cpp 
        DigitTester.cpp 
        
)
add_executable(TestCxx ${TestsToRun})
target_link_libraries(TestCxx src_lib)
target_include_directories(TestCxx 
        PRIVATE "./../src"
)
add_test(NAME Utilities.GetDigits COMMAND TestCxx DigitTester)
