#pragma once
#include "BinaryFunctionMap.h"
#include <vector>

class FunctionTree
{
public:
  float applyTree(float, float);
  FunctionTree(BinaryFunctionMap map);
};