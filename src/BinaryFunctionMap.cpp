#include <math.h>
#include "BinaryFunctionMap.hpp"

float BinaryFunctionMap::applyBasic(const float x, const float y, int n)
{
  if (n % 5 == 1)
    return y > x ? y - x : x - y;
  if (n % 5 == 2)
    return x * y;
  if (n % 5 == 3)
    return x;
  if (n % 5 == 4)
    return y;
  return (x + y) / 2;
}

float BinaryFunctionMap::applyComplex(const float z, int n)
{
  if (n == 1)
    return sin(6.282f * z);
  else if (n == 2)
    return cos(6.282f * z);
  else if (n == 3)
    return log(1.717f * z + 1);
  return z;
}

float BinaryFunctionMap::applyFunction(const float x, const float y, int n)
{
  float z = applyBasic(x, y, n);
  return applyComplex(z, n);
}
