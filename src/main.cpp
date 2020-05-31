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

std::vector<std::vector<int>> getRandomPairsArray(unsigned int length)
{
  std::vector<std::vector<int>> pairs = {};
  for (int i = 0; i < length; i++)
  {
    std::vector<int> pair = {rand() % 12, rand() % 12};
    pairs.push_back(pair);
  }
  return pairs;
}

std::vector<unsigned char> getImage(unsigned int width, unsigned int height)
{
  std::vector<std::vector<int>> pairsArray = getRandomPairsArray(4);
  BinaryFunctionMap map;
  FunctionTree tree(pairsArray, map);
  std::vector<std::vector<int>> coeffArray = {{2, 2, 13, 4}, {7, 2, -1, 1, 8}, {4, 6, 2, 1, 1}};
  RGBPolynomial poly(coeffArray);

  std::vector<unsigned char> image = {};

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      std::vector<float> vec = poly.applyPoly(tree.applyTree(((float)i / width), (float)j / height));
      image.push_back(vec[0] * 255);
      image.push_back(vec[1] * 255);
      image.push_back(vec[2] * 255);
      image.push_back(255);
    }
  }
  return image;
}

int setSeed(int seed)
{
  if (seed < 0)
    seed = time(NULL);
  srand(seed);
  std::cout << seed << std::endl;
  return seed;
}

int main(int argc, char const *argv[])
{
  int seed = setSeed(-1);
  std::string path = "images/";
  const char *fileName = path.append(std::to_string(seed)).append(".png").c_str();

  unsigned int width{256};
  unsigned int height{256};
  std::vector<unsigned char> image = getImage(width, height);

  encodeOneStep(fileName, image, width, height);
  return 0;
}