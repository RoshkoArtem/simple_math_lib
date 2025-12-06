include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main  
)
FetchContent_MakeAvailable(googletest)

add_executable(MathLibUnitTests math_library_tests.cpp)
target_link_libraries(MathLibUnitTests
  PRIVATE
    gtest_main
    math_library
)

enable_testing()
add_test(NAME math_library_gtests COMMAND MathLibUnitTests)