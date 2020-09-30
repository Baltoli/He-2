add_library(analysis
  src/conditional_analysis.cpp
  src/indirection_analysis.cpp
  src/preprocess.cpp
  src/staticinfo.cpp
  src/tree_analysis.cpp
  src/x86_analysis.cpp)

target_include_directories(analysis
  PUBLIC include)

target_link_libraries(analysis
  utility
  common)
