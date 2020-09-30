add_library(trees
  src/abs_node.cpp
  src/comp_abs_node.cpp
  src/conc_node.cpp
  src/node.cpp
  src/abs_tree.cpp
  src/comp_abs_tree.cpp
  src/conc_tree.cpp
  src/tree.cpp)

target_link_libraries(trees
  common
  utility
  analysis)

target_include_directories(trees
  PUBLIC include)
