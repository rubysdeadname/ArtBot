#include "ImageCreator.hpp"
#include <iostream>
#include <string>

void ImageCreator::encodeOneStep(const char *filename, std::vector<unsigned char> &image, unsigned width, unsigned height)
{
  unsigned error = lodepng::encode(filename, image, width, height);
  if (error)
    std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

int ImageCreator::getRandomInt(int upperLimit)
{
  return (int)(upperLimit * (float)rand() / (float)RAND_MAX);
}

std::vector<int> ImageCreator::getRandomIntArray(int length, int upperLimit)
{
  std::vector<int> randArr;
  randArr.reserve(length);

  for (int i = 0; i < length; ++i)
  {
    randArr.push_back(getRandomInt(upperLimit));
  }
  return randArr;
}

std::vector<std::pair<int, int>> ImageCreator::getRandomPairsArray(unsigned int length)
{
  std::vector<std::pair<int, int>> pairs;
  pairs.reserve(length);

  for (unsigned int i = 0; i < length; ++i)
  {
    std::pair<int, int> pair = {rand() % 6, rand() % 6};
    pairs.push_back(pair);
  }
  return pairs;
}

std::vector<unsigned char> ImageCreator::getImage(unsigned int width, unsigned int height)
{
  std::vector<std::pair<int, int>> pairsArray = getRandomPairsArray(12);
  BinaryFunctionMap map;
  FunctionTree tree(pairsArray, map);

  std::vector<std::vector<int>> coeffArray = {
      getRandomIntArray((rand() % 3) + 3, 10),
      getRandomIntArray((rand() % 3) + 3, 10),
      getRandomIntArray((rand() % 3) + 3, 10),
  };
  RGBPolynomial poly(coeffArray);

  std::vector<unsigned char> image;
  image.reserve(height * width);

  for (unsigned int i = 0; i < height; ++i)
  {
    for (unsigned int j = 0; j < width; ++j)
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

int ImageCreator::setSeed(int seed)
{
  if (seed < 0)
    seed = time(NULL);
  srand(seed);
  std::cout << seed << std::endl;
  return seed;
}

void ImageCreator::create(int randSeed, unsigned int dim, std::string name)
{
  int seed = setSeed(randSeed);
  std::vector<unsigned char> image = getImage(dim, dim);
  std::string path = "images/";
  if (name == "")
    name = std::to_string(seed);
  const char *fileName = path.append(name).append(".png").c_str();

  encodeOneStep(fileName, image, dim, dim);
}
