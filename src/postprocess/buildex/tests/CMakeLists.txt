add_executable(test_vector
  src/test_vector.cpp)

target_link_libraries(test_vector
  common
  utility
  analysis)
