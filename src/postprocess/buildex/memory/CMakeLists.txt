add_library(memory
  src/memanalysis.cpp
  src/memdump.cpp
  src/meminstrace.cpp
  src/memregions.cpp)

target_include_directories(memory
  PUBLIC include)

target_link_libraries(memory
  analysis
  common
  trees
  utility)
