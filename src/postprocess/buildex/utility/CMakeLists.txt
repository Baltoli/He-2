add_library(utility
  src/fileparser.cpp
  src/print_helper.cpp)

target_include_directories(utility
  PUBLIC include)

target_link_libraries(utility
  analysis
  common)
