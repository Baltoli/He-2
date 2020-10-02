add_library(common
  src/imageinfo.cpp
  src/meminfo.cpp
  src/utilities.cpp)

target_include_directories(common
  PUBLIC include)

target_link_libraries(common
  Halide::Halide
  Halide::ImageIO
  stb)
