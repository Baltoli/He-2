add_executable(image_blur src/blur.cpp)
target_link_libraries(image_blur
  common)

add_executable(image_invert src/invert.cpp)
target_link_libraries(image_invert
  common)

##basic tests sources
#add_executable(basic_arith src_basic/arith.cpp)
#add_executable(basic_loop_red src_basic/loop_red.cpp)
#add_executable(basic_convoluted src_basic/convoluted.cpp)
#add_executable(basic_data_parallel src_basic/data_parallel.cpp)
#add_executable(basic_calls src_basic/calls.cpp)
#add_executable(basic_recursive src_basic/recursive.cpp)
#add_executable(basic_ifelse src_basic/ifelse.cpp)
#add_executable(basic_producer_consumer src_basic/producer_consumer.cpp)
#add_executable(basic_do_nothing src_basic/do_nothing.cpp)
