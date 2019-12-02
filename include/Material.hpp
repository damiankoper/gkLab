#pragma once
#include <GL/glut.h>

class Material
{

public:
    Material();
    ~Material();

    GLfloat ambient[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat diffuse[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specular[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess = {20.0};

    void apply();
};