#pragma once
#include <GL/glut.h>
#include <Color.hpp>
class Point
{

public:
    Point(float x, float y, float z, GLubyte r, GLubyte g, GLubyte b)
        : color({r, g, b}), x(x), y(y), z(z){};
    ~Point();
    void callGlVertex3f();
    void callGlColor3f();
    void drawWithColor();
    float x = 0;
    float y = 0;
    float z = 0;
    
    float nx = 0;
    float ny = 0;
    float nz = 0;
    Color color;
};