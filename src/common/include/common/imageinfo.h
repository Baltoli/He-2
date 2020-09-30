#ifndef _EXALGO_IMAGEINFO_H
#define _EXALGO_IMAGEINFO_H

#include <stdint.h>
#include <string>

using namespace std;

struct image_t {
  uint32_t height;
  uint32_t width;
  uint32_t colors; /* number of colors in the image */
  uint32_t bits_per_color;
  uint32_t bits_per_pixel;
  uint32_t is_alpha;
  char* image_array; /* this is just a stream of bytes - no type
                        information column major format */
};

struct bitmap {
  int height;
  int width;
  int channels;
  char* buffer;
};

uintptr_t initialize_image_subsystem();
void shutdown_image_subsystem(uintptr_t token);

void save_image(bitmap* image, const char* file);
bitmap* open_image(const char* filename);
bitmap* create_image(uint32_t width, uint32_t height);

char* get_image_buffer(bitmap* image);
/* void update_image_buffer(Gdiplus::Bitmap* image, byte* buffer); */
image_t* populate_imageinfo(bitmap* image);

#endif
