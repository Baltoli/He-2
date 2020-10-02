#ifndef _EXALGO_IMAGEINFO_H
#define _EXALGO_IMAGEINFO_H

/* #include <common/static_image.h> */

#include <Halide.h>

#include <algorithm>
#include <cstdint>
#include <string>

template <typename T>
Halide::Buffer<T> load_halide_image(char* filename);

template <typename T>
void save_halide_image(char* filename, Halide::Buffer<T> im);

/******copied from image_io.h **********/

// Convert to u8
inline void convert(uint8_t in, uint8_t& out) { out = in; }
inline void convert(uint16_t in, uint8_t& out) { out = in >> 8; }
inline void convert(uint32_t in, uint8_t& out) { out = in >> 24; }
inline void convert(int8_t in, uint8_t& out) { out = in; }
inline void convert(int16_t in, uint8_t& out) { out = in >> 8; }
inline void convert(int32_t in, uint8_t& out) { out = in >> 24; }
inline void convert(float in, uint8_t& out) { out = (uint8_t)(in * 255.0f); }
inline void convert(double in, uint8_t& out) { out = (uint8_t)(in * 255.0f); }

// Convert to u16
inline void convert(uint8_t in, uint16_t& out) { out = in << 8; }
inline void convert(uint16_t in, uint16_t& out) { out = in; }
inline void convert(uint32_t in, uint16_t& out) { out = in >> 16; }
inline void convert(int8_t in, uint16_t& out) { out = in << 8; }
inline void convert(int16_t in, uint16_t& out) { out = in; }
inline void convert(int32_t in, uint16_t& out) { out = in >> 16; }
inline void convert(float in, uint16_t& out)
{
  out = (uint16_t)(in * 65535.0f);
}
inline void convert(double in, uint16_t& out)
{
  out = (uint16_t)(in * 65535.0f);
}

// Convert from u8
inline void convert(uint8_t in, uint32_t& out) { out = in << 24; }
inline void convert(uint8_t in, int8_t& out) { out = in; }
inline void convert(uint8_t in, int16_t& out) { out = in << 8; }
inline void convert(uint8_t in, int32_t& out) { out = in << 24; }
inline void convert(uint8_t in, float& out) { out = in / 255.0f; }
inline void convert(uint8_t in, double& out) { out = in / 255.0f; }

// Convert from u16
inline void convert(uint16_t in, uint32_t& out) { out = in << 16; }
inline void convert(uint16_t in, int8_t& out) { out = in >> 8; }
inline void convert(uint16_t in, int16_t& out) { out = in; }
inline void convert(uint16_t in, int32_t& out) { out = in << 16; }
inline void convert(uint16_t in, float& out) { out = in / 65535.0f; }
inline void convert(uint16_t in, double& out) { out = in / 65535.0f; }

inline bool ends_with_ignore_case(std::string a, std::string b)
{
  if (a.length() < b.length()) {
    return false;
  }
  std::transform(a.begin(), a.end(), a.begin(), ::tolower);
  std::transform(b.begin(), b.end(), b.begin(), ::tolower);
  return a.compare(a.length() - b.length(), b.length(), b) == 0;
}

inline int is_little_endian()
{
  int value = 1;
  return ((char*)&value)[0] == 1;
}

#define SWAP_ENDIAN16(little_endian, value)                                    \
  if (little_endian) {                                                         \
    (value) = (((value)&0xff) << 8) | (((value)&0xff00) >> 8);                 \
  }

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
