#include "halide_blur_hvscan_gen.h"

#include <common/imageinfo.h>

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string>

using namespace Halide;

Buffer<uint8_t> halide_function(Buffer<uint8_t> in, Buffer<uint8_t> out)
{
  // Call it once to initialize the halide runtime stuff
  // halide_blur_hvscan_gen(in, out);
  return out;
}

int main(int argc, char** argv)
{
  auto token = initialize_image_subsystem();
  char value = getchar();

  std::string name(argv[1]);
  Buffer<uint8_t> input = load_halide_image<uint8_t>(argv[1]);
  Buffer<uint8_t> output(input.width() - 2, input.height() - 2);

  if (value == 'a') {
    // halide_blur_hvscan_gen(input,input, input, 4, output);
    // halide_blur_hvscan_gen(input,2.2, 5, output);
    halide_blur_hvscan(*input.get(), *output.get());
  }
  save_halide_image<uint8_t>(argv[2], output);
  shutdown_image_subsystem(token);

  return 0;
}
