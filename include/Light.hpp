#pragma once
#include <GL/glut.h>
#include <Color.hpp>
class Light
{

public:
    Light();
    ~Light();

    GLfloat position[4] = {0.0, 0.0, 10.0, 1.0};
    GLfloat ambient[4] = {0.1, 0.1, 0.1, 1.0};
    GLfloat diffuse[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specular[4] = {1.0, 1.0, 1.0, 1.0};

    GLfloat constant = {1.0};
    GLfloat linear = {0.05};
    GLfloat quadratic = {0.001};

    void init(int n);
    void calcPosition();
    void calcColor();

    float rDistance = 10.;
    float azimuth = 0;
    float elevation = 0;

    Color color = {255,255,255};

    void drawSphere();

private:
    int n;
};