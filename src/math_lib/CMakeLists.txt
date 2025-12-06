set(SOURCES math_lib.cpp)
set(HEADERS include/math_lib.h)
add_library(math_library STATIC ${SOURCES} ${HEADERS})
target_include_directories(math_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)