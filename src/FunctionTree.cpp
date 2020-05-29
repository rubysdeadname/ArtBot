#include "BinaryFunctionMap.h"
#include <vector>

class FunctionTree
{
private:
  BinaryFunctionMap functionMap;
  std::vector<std::vector<int>> pairsArray;

public:
  float applyTree(float initialX, float initialY)
  {
    float x = initialX, y = initialY, z = 0;
    for (std::vector<int> pair : pairsArray)
    {
      x = functionMap.applyFunction(x, y, pair[0]), y = functionMap.applyFunction(x, y, pair[1]);
    }
    return (x * y);
  }

  FunctionTree(BinaryFunctionMap map)
  {
    functionMap = map;
  }
};
