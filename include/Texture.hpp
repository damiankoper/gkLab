#pragma once
#include <string>
#include <GL/glut.h>
class Texture
{

public:
    Texture(std::string filename);
    ~Texture();

    void apply();

private:
    GLbyte *pBytes;
    GLint width = 0;
    GLint height = 0;
    GLint components = GL_RGB8;
    GLenum format = GL_BGR_EXT;
};