add_executable(image_blur src/blur.cpp)
target_link_libraries(image_blur
  common)

add_executable(image_invert src/invert.cpp)
target_link_libraries(image_invert
  common)

add_executable(basic_arith src/arith.cpp)
add_executable(basic_loop_red src/loop_red.cpp)
add_executable(basic_convoluted src/convoluted.cpp)
add_executable(basic_data_parallel src/data_parallel.cpp)
add_executable(basic_calls src/calls.cpp)
add_executable(basic_recursive src/recursive.cpp)
add_executable(basic_ifelse src/ifelse.cpp)
add_executable(basic_producer_consumer src/producer_consumer.cpp)
add_executable(basic_do_nothing src/do_nothing.cpp)
