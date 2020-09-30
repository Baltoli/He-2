add_library(halide
  src/halide.cpp)

target_include_directories(halide
  PUBLIC include)

target_link_libraries(halide
  common
  memory
  trees
  utility)
