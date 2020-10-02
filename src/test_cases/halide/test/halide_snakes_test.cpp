#include "halide_snakes_gen.h"

#include <common/imageinfo.h>

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <string>

using namespace Halide;

uint8_t scale = 2;

Buffer<uint8_t> halide_function(Buffer<uint8_t> in)
{

  Buffer<uint8_t> out(in.width() / scale, in.height() / scale);

  // Call it once to initialize the halide runtime stuff
  halide_snakes(*in.get(), *out.get());

  return out;
}

int main(int argc, char** argv)
{
  auto token = initialize_image_subsystem();

  std::string name(argv[1]);
  Buffer<uint8_t> input = load_halide_image<uint8_t>(argv[1]);
  Buffer<uint8_t> output = halide_function(input);
  save_halide_image<uint8_t>(argv[2], output);

  shutdown_image_subsystem(token);

  return 0;
}
