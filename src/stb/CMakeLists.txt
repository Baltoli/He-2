add_library(stb
  src/image.c
  src/image_write.c)

target_include_directories(stb
  PUBLIC include)
