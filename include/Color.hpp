#pragma once
#include <GL/glut.h>

class Color
{

public:
    Color(GLubyte r, GLubyte g, GLubyte b) : r(r), g(g), b(b) {}
    ~Color();
    GLubyte r = 255;
    GLubyte g = 255;
    GLubyte b = 255;

    void apply();
};