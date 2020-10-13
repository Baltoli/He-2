#include "halide_threshold_gen.h"

#include <common/imageinfo.h>

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <string>

using namespace Halide;
using namespace Halide::Tools;

uint8_t scale = 2;

Buffer<uint8_t> halide_function(Buffer<uint8_t> in)
{
  Buffer<uint8_t> out(in.width(), in.height());

  // Call it once to initialize the halide runtime stuff
  halide_threshold(*in.get(), *out.get());

  return out;
}

int main(int argc, char** argv)
{
  auto token = initialize_image_subsystem();

  std::string name(argv[1]);
  Buffer<uint8_t> input = load_image(argv[1]);
  Buffer<uint8_t> output = halide_function(input);
  save_image(output, argv[2]);

  shutdown_image_subsystem(token);

  return 0;
}
