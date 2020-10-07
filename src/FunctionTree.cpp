#include "BinaryFunctionMap.hpp"
#include "FunctionTree.hpp"
#include <vector>

float FunctionTree::applyTree(float initialX, float initialY)
{
  float x = initialX, y = initialY;
  for (std::vector<int> pair : pairsArray)
  {
    x = functionMap.applyFunction(x, y, pair[0]), y = functionMap.applyFunction(x, y, pair[1]);
  }
  return (x * y);
}

FunctionTree::FunctionTree(std::vector<std::vector<int>> pairs, BinaryFunctionMap map)
{
  functionMap = map;
  pairsArray = pairs;
}
