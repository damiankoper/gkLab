#include "NumericUtils.hpp"

NumericUtils::NumericUtils()
{
}
NumericUtils::~NumericUtils()
{
}

GLubyte NumericUtils::randByte()
{
  return rand() % 256;
}

void NumericUtils::glSetRandColor(float r, float g, float b)
{
  glColor3ub(randByte() * r, randByte() * g, randByte() * b);
}
