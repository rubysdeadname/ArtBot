#include <math.h>
#include "BinaryFunctionMap.h"

float BinaryFunctionMap::applyBasic(const float x, const float y, int n)
{
  if (n % 3 == 1)
    return y > x ? y - x : x - y;
  if (n % 3 == 2)
    return x * y;
  return (x + y) / 2;
}

float BinaryFunctionMap::applyComplex(const float z, int n)
{
  if (n <= 3)
    return z;
  else if (n <= 6)
    return sin(z);
  else if (n <= 9)
    return cos(z);
  return tan(z);
}

float BinaryFunctionMap::applyFunction(const float x, const float y, int n)
{
  float z = applyBasic(x, y, n);
  return applyComplex(z, n);
}
