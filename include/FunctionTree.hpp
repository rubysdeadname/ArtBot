#pragma once
#include "BinaryFunctionMap.hpp"
#include <vector>

class FunctionTree
{
private:
  BinaryFunctionMap functionMap;
  std::vector<std::pair<int, int>> pairsArray;

public:
  float applyTree(float, float);
  FunctionTree(std::vector<std::pair<int, int>> pairsArray, BinaryFunctionMap map);
};
