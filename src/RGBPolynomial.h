#pragma once

#include <vector>

class RGBPolynomial
{
public:
  std::vector<float> applyPoly(const float z);
  RGBPolynomial(std::vector<std::vector<int>> coefficients);
};