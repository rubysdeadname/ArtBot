#include <vector>

class RGBPolynomial
{
private:
  std::vector<std::vector<int>> coeffs;
  float norm(float z)
  {
    int c = z < 0 ? -z : z;
    return z / c;
  }

public:
  std::vector<float> applyPoly(const float z)
  {
    std::vector<float> vec = {};
    vec.push_back(norm((z * z) * coeffs[0][0] + z * coeffs[0][1] + coeffs[0][2]));
    vec.push_back(norm((z * z) * coeffs[1][0] + z * coeffs[1][1] + coeffs[1][2]));
    vec.push_back(norm((z * z) * coeffs[2][0] + z * coeffs[2][1] + coeffs[2][2]));
    return vec;
  }

  RGBPolynomial(std::vector<std::vector<int>> coefficients)
  {
    coeffs = coefficients;
  }
};