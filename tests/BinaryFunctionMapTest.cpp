#include "BinaryFunctionMap.hpp"
#include "UnitTest++/UnitTest++.h"

SUITE(BinaryFunctionMapTest)
{
  TEST(applyBasic_returnsExpected)
  {
    BinaryFunctionMap binaryFunctionMap;
    float result = binaryFunctionMap.applyFunction(0, 0, 1);
    CHECK_EQUAL(0, result);
  }
}