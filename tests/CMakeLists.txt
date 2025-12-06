include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

include_directories(${CMAKE_SOURCE_DIR}/src/math_lib/include)

add_executable(MathLibUnitTests
    math_library_tests.cpp
)

target_link_libraries(MathLibUnitTests
 PRIVATE
  GTest::GTest
  math_library
)

add_test(math_library_gtests MathLibUnitTests)
