cmake_minimum_required(VERSION 3.20)
project(MathLibExample)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/math_lib/include)
add_executable(MathLibExample main.cpp)

add_subdirectory(math_lib)
# Link the executable with the logger library
target_link_libraries(MathLibExample math_library)