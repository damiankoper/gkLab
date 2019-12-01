
#include "DrawingUtils.hpp"

DrawingUtils::DrawingUtils()
{
}

DrawingUtils::~DrawingUtils()
{
}

void DrawingUtils::axis(float length)
{
    float x_min[3] = {-length, 0.0, 0.0};
    float x_max[3] = {length, 0.0, 0.0};

    float y_min[3] = {0.0, -length, 0.0};
    float y_max[3] = {0.0, length, 0.0};

    float z_min[3] = {0.0, 0.0, -length};
    float z_max[3] = {0.0, 0.0, length};
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3fv(x_min);
    glVertex3fv(x_max);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);

    glVertex3fv(y_min);
    glVertex3fv(y_max);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);

    glVertex3fv(z_min);
    glVertex3fv(z_max);
    glEnd();
}

void DrawingUtils::text(float x, float y, void *font, const unsigned char *string)
{

    glColor3f(1., 1., 1.);
    glRasterPos2f(x, y);

    glutBitmapString(font, string);
}