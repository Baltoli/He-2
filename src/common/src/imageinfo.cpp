#include <iostream>

#include <common/common_defines.h>
#include <common/imageinfo.h>

using namespace std;

uintptr_t initialize_image_subsystem() { return 0; }

void shutdown_image_subsystem(uintptr_t token) { }

void save_image(bitmap* image, const char* file)
{
  UNIMPLEMENTED();
  /*
          CLSID clsId;

          wchar_t * file_wchar = new wchar_t[strlen(file) + 1];;
          mbstowcs(file_wchar, file, strlen(file) + 1);

          string filename(file);

          string extension = "";
          int index = -1;
          for (int i = filename.size() - 1; i >= 0; i--){
                  if (filename[i] == '.'){
                          index = i + 1;
                          break;
                  }
          }

          if (index != -1){

                  for (int i = index; i<filename.size(); i++){
                          extension += filename[i];
                  }

          }

          // image/bmp
          // image/jpeg
          // image/gif
          // image/tiff
          // image/png

          if ((extension.compare("jpg") == 0)){
                  GetEncoderClsid(L"image/jpeg", &clsId);
          }
          else if ((extension.compare("png") == 0)){
                  GetEncoderClsid(L"image/png", &clsId);
          }
          else{
                  cout << "error: unknown image type" << endl;
                  return;
          }

          image->Save(file_wchar, &clsId);
          */
}

bitmap* open_image(const char* filename)
{
  /* DEBUG_PRINT(("opening image - %s\n", filename), 3); */

  UNIMPLEMENTED();

  /* wchar_t * file_wchar = new wchar_t[strlen(filename) + 1]; */

  /* mbstowcs(file_wchar, filename, strlen(filename) + 1); */

  /* Gdiplus::Bitmap *image = Gdiplus::Bitmap::FromFile(file_wchar); */

  /* return image; */
}

bitmap* create_image(uint32_t width, uint32_t height)
{
  UNIMPLEMENTED();

  /* Gdiplus::Bitmap * image = new Gdiplus::Bitmap(width, height); */
  /* return image; */
}

image_t* populate_imageinfo(bitmap* image)
{

  image_t* imageinfo = new image_t;

  imageinfo->width = image->width;
  imageinfo->height = image->height;
  imageinfo->image_array = get_image_buffer(image);

  printf("height - %d, width - %d\n", imageinfo->height, imageinfo->width);

  return imageinfo;
}

char* get_image_buffer(bitmap* image)
{
  UNIMPLEMENTED();

  /*   Gdiplus::Status ok; */

  /*   byte* buffer = new byte[image->GetHeight() * image->GetWidth() * 3]; */

  /*   uint32_t height = image->GetHeight(); */
  /*   uint32_t width = image->GetWidth(); */
  /*   DEBUG_PRINT(("height : %d, width : %d\n", height, width), 3); */

  /*   for (int i = 0; i < image->GetWidth(); i++) { */
  /*     for (int j = 0; j < image->GetHeight(); j++) { */
  /*       Gdiplus::Color color; */
  /*       ok = image->GetPixel(i, j, &color); */

  /*       if (ok != 0) { */
  /*         std::cout << "error" << std::endl; */
  /*         exit(-1); */
  /*       } else { */

  /*         buffer[(0 * height + j) * width + i] = color.GetR(); */
  /*         buffer[(1 * height + j) * width + i] = color.GetG(); */
  /*         buffer[(2 * height + j) * width + i] = color.GetB(); */
  /*       } */
  /*     } */
  /*   } */

  /*   return buffer; */
}

void update_image_buffer(bitmap* image, char* buffer)
{
  UNIMPLEMENTED();

  /*   // update the bitmap image */
  /*   uint32_t height = image->GetHeight(); */
  /*   uint32_t width = image->GetWidth(); */

  /*   for (int i = 0; i < image->GetWidth(); i++) { */
  /*     for (int j = 0; j < image->GetHeight(); j++) { */
  /*       Gdiplus::Color color; */
  /*       Gdiplus::ARGB value = 0; */

  /*       value |= ((uint32_t)255) << 24; // create opaque images */
  /*       value |= (((uint32_t)buffer[(0 * height + j) * width + i]) << 16); */
  /*       value |= (((uint32_t)buffer[(1 * height + j) * width + i]) << 8); */
  /*       value |= (((uint32_t)buffer[(2 * height + j) * width + i])); */

  /*       color.SetValue(value); */

  /*       image->SetPixel(i, j, color); */
  /*     } */
  /*   } */
}
