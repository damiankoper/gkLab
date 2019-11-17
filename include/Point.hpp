#pragma once
#include <GL/glut.h>

class Point
{

public:
    Point(float x, float y, float z, GLubyte r, GLubyte g, GLubyte b)
        : color({r, g, b}), x(x), y(y), z(z){};
    ~Point();
    void callGlVertex3f();
    void callGlColor3f();
    void drawWithColor();

    struct Color
    {
        GLubyte r = 255;
        GLubyte g = 255;
        GLubyte b = 255;
    };
    float x = 0;
    float y = 0;
    float z = 0;
    Color color;
};