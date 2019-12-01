#pragma once
#include <GL/freeglut.h>

class DrawingUtils
{
public:
    static void axis(float length = 5.);
    static void text(float x, float y, void *font, const unsigned char *string);

private:
    DrawingUtils();
    virtual ~DrawingUtils();
};