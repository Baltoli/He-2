add_executable(image_cons
  src/main.cpp
)

target_include_directories(image_cons
  PRIVATE include)

target_link_libraries(image_cons common)
