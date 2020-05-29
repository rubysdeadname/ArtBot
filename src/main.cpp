#include "lodepng.h"
#include <iostream>
#include "FunctionTree.h"
#include "RGBPolynomial.h"

void encodeOneStep(const char *filename, std::vector<unsigned char> &image, unsigned width, unsigned height)
{
  unsigned error = lodepng::encode(filename, image, width, height);
  if (error)
    std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

std::vector<unsigned char> getImage()
{
  std::vector<std::vector<unsigned int>> pairsArray = {{1, 7}, {6, 4}, {2, 8}, {3, 5}};
  BinaryFunctionMap map;
  FunctionTree tree(map, pairsArray);
  std::vector<std::vector<int>> coeffArray = {{1, 2, 3}, {2, 1, 3}, {3, 1, 2}};
  RGBPolynomial poly(coeffArray);

  unsigned int width{8};
  unsigned int height{8};
  std::vector<unsigned char> image = {};

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      std::vector<float> vec = poly.applyPoly(tree.applyTree(i, j));
      image.push_back(vec[0] * 255);
      image.push_back(vec[1] * 255);
      image.push_back(vec[2] * 255);
      image.push_back(255);
    }
  }
  return image;
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  unsigned int width{8};
  unsigned int height{8};

  std::vector<unsigned char> image = getImage();

  // for (int i = 0; i < height; i++)
  // {
  //   for (int j = 0; j < width; j++)
  //   {
  //     image.push_back(std::rand() % 255);
  //     image.push_back(std::rand() % 255);
  //     image.push_back(std::rand() % 255);
  //     image.push_back(255);
  //   }
  // }

  encodeOneStep("test.png", image, width, height);
  return 0;
}