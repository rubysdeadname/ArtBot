#include <math.h>
#include <vector>
#include "RGBPolynomial.h"

float RGBPolynomial::norm(float z)
{
  while (z > 1)
    z--;
  return z;
}

float RGBPolynomial::applySinglePoly(const float z, std::vector<int> coeffs)
{
  float res = 0;
  for (int i = coeffs.size() - 1; i >= 0; i--)
    res += coeffs[i] * pow(z, i);
  return res;
}

std::vector<float> RGBPolynomial::applyPoly(const float z)
{
  std::vector<float> vec = {};
  vec.push_back(norm(applySinglePoly(z, coeffs[0])));
  vec.push_back(norm(applySinglePoly(z, coeffs[1])));
  vec.push_back(norm(applySinglePoly(z, coeffs[2])));
  return vec;
}

RGBPolynomial::RGBPolynomial(std::vector<std::vector<int>> coefficients)
{
  coeffs = coefficients;
}