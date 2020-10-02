#ifndef _EXALGO_IMAGEINFO_H
#define _EXALGO_IMAGEINFO_H

/* #include <common/static_image.h> */

#include <Halide.h>
#include <halide_image_io.h>

#include <algorithm>
#include <cstdint>
#include <string>

template <typename T>
Halide::Buffer<T> load_halide_image(char* filename);

template <typename T>
void save_halide_image(char* filename, Halide::Buffer<T> im);

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
void update_image_buffer(bitmap* image, char* buffer);
image_t* populate_imageinfo(bitmap* image);

template <typename T>
Halide::Buffer<T> load_halide_image(char* filename)
{
  return Halide::Buffer<T>();
  /*
    wchar_t* file_wchar = new wchar_t[strlen(filename) + 1];
    ;
    mbstowcs(file_wchar, filename, strlen(filename) + 1);

    Gdiplus::Bitmap* image = Gdiplus::Bitmap::FromFile(file_wchar);

    Gdiplus::Status ok;

    int width, height;
    width = image->GetWidth();
    height = image->GetHeight();

    Image<T> im(width, height, COLORS);

    T* im_data = (T*)im.data();

    for (int j = 0; j < height; j++) {
      for (int i = 0; i < width; i++) {

        Gdiplus::Color color;
        ok = image->GetPixel(i, j, &color);

        // we are getting byte-wise color so no need to differentiate 8 and 16
        // convert(color.GetR(), im_data[(0 * height + j)*width + i]);
        // convert(color.GetG(), im_data[(1 * height + j)*width + i]);
        // convert(color.GetB(), im_data[(2 * height + j)*width + i]);

        im_data[i + j * width + 0 * width * height] = color.GetR();
        im_data[i + j * width + 1 * width * height] = color.GetG();
        im_data[i + j * width + 2 * width * height] = color.GetB();
      }
    }

    delete image;

    im(0, 0, 0) = im(0, 0, 0);
    return im;
    */
}

template <typename T>
void save_halide_image(char* filename, Halide::Buffer<T> im)
{
  /*
    int width, height, channels;
    width = im.width();
    height = im.height();
    channels = im.channels();

    Gdiplus::Bitmap* image = new Gdiplus::Bitmap(width, height);

    Gdiplus::Status ok;

    for (int j = 0; j < height; j++) {
      for (int i = 0; i < width; i++) {

        Gdiplus::Color color;
        Gdiplus::ARGB value = 0;

        uint8_t color_val;

        value |= ((uint32_t)255) << 24; // we don't care about this
  for (int k = 0; k < COLORS; k++) {
    color_val = im(i, j, (channels <= k) ? channels - 1 : k);
    // convert(im(i, j, (channels <= k) ? channels - 1 : k), color_val);
  value |= ((uint32_t)color_val) << (16 - 8 * k);
}

color.SetValue(value);

image->SetPixel(i, j, color);
}
}

save_image(image, filename);

delete image;
*/
}

#endif
