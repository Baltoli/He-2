add_library(common
  src/meminfo.cpp
  src/utilities.cpp)

target_include_directories(common
  PUBLIC include)

target_link_libraries(common
  stb)
