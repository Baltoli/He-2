#include <common/imageinfo.h>

#include <cassert>
#include <cstdint>
#include <cwchar>
#include <iostream>
#include <string>

using namespace std;

void blur(char* input, char* output, int height, int width, int fields)
{
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      uint32_t index = (i * width + j) * fields;

      int radius = 3;

      if ((i >= radius / 2) && (j >= radius / 2) && (i < height - radius / 2)
          && (j < width - radius / 2)) {
        for (int x = i - radius / 2; x <= i + radius / 2; x++) {
          for (int y = j - radius / 2; y <= j + radius / 2; y++) {
            for (int k = 0; k < fields; k++) {
              output[index + k]
                  += ((input[(x * width + y) * fields + k])
                      / (radius * radius));
            }
          }
        }

      } else {
        for (int k = 0; k < fields; k++) {
          output[index + k] = 0;
        }
      }
    }
  }
}

int main(int argc, char* argv[])
{
  auto token = initialize_image_subsystem();

  assert(argc == 3);

  auto input_file = argv[1];
  auto output_file = argv[2];

  bitmap* image = open_image(input_file);

  char* input_buffer = get_image_buffer(image);
  uint32_t width = image->width;
  uint32_t height = image->height;
  uint32_t fields = image->channels;

  /* for inverse we need the same sized array as input_buffer */
  char* output_buffer = new char[height * width * fields];
  for (int i = 0; i < height * width * fields; i++) {
    output_buffer[i] = 0;
  }

  blur(input_buffer, output_buffer, height, width, 3);

  update_image_buffer(image, output_buffer);

  save_image(image, output_file);

  delete image;

  shutdown_image_subsystem(token);

  return 0;
}

