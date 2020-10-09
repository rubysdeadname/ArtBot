#include "BinaryFunctionMap.hpp"
#include "FunctionTree.hpp"
#include <vector>

float FunctionTree::applyTree(float initialX, float initialY)
{
  float x = initialX, y = initialY;
  for (auto pair : pairsArray)
  {
    x = functionMap.applyFunction(x, y, pair.first), y = functionMap.applyFunction(x, y, pair.second);
  }
  return (x * y);
}

FunctionTree::FunctionTree(std::vector<std::pair<int, int>> pairs, BinaryFunctionMap map)
{
  functionMap = map;
  pairsArray = pairs;
}
