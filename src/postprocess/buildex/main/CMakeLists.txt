add_executable(buildex
  src/main.cpp
  src/procedure.cpp)

target_link_libraries(buildex
  analysis
  common
  halide
  memory
  trees
  utility)
