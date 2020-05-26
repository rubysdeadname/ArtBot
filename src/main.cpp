#include "lodepng.h"
#include <iostream>

/*
3 ways to encode a PNG from RGBA pixel data to a file (and 2 in-memory ways).
NOTE: this samples overwrite the file or test.png without warning!
*/

//g++ lodepng.cpp examples/example_encode.cpp -I./ -ansi -pedantic -Wall -Wextra -O3

//Example 1
//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char *filename, std::vector<unsigned char> &image, unsigned width, unsigned height)
{
  //Encode the image
  unsigned error = lodepng::encode(filename, image, width, height);

  //if there's an error, display it
  if (error)
    std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

int main(int argc, char const *argv[])
{
  unsigned int width = 20;
  unsigned int height {20};

  std::vector<unsigned char> image = {};

  for(int i = 0; i < width * height; i++) {
    image.push_back(std::rand() % 255);
    image.push_back(std::rand() % 255);
    image.push_back(std::rand() % 255);
    image.push_back(255);
  }

  encodeOneStep("test.png", image, width, height);
  return 0;
}