#include "Point.hpp"

Point::~Point()
{
}

void Point::callGlColor3f()
{
    glColor3ub(color.r, color.g, color.b);
}

void Point::callGlVertex3f()
{
    glVertex3f(x, y, z);
}

void Point::drawWithColor()
{
    color.apply();
    glNormal3f(nx,ny,nz);
    glVertex3f(x, y, z);
}