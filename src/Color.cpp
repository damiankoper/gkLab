#include "Color.hpp"

Color::~Color()
{
}

void Color::apply()
{
  glColor3ub(r, g, b);
}