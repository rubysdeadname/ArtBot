#pragma once
#include "lodepng.hpp"
#include <iostream>
#include <string>
#include "FunctionTree.hpp"
#include "RGBPolynomial.hpp"
#include "ArgumentHandler.hpp"

class ImageCreator
{
private:
  void encodeOneStep(const char *filename, std::vector<unsigned char> &image, unsigned width, unsigned height);
  int getRandomInt(int upperLimit);
  std::vector<int> getRandomIntArray(int length, int upperLimit);
  std::vector<std::pair<int, int>> getRandomPairsArray(unsigned int length);
  std::vector<unsigned char> getImage(unsigned int width, unsigned int height);
  int setSeed(int seed);

public:
  void create(int randSeed, unsigned int dim, std::string name);
};
