#pragma once
#include <GL/glut.h>

class NumericUtils
{

public:
    static void glSetRandColor(float r = 1., float g = 1., float b = 1.);
    static GLubyte randByte();

private:
    NumericUtils();
    virtual ~NumericUtils();
};