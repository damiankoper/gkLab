#pragma once
#include <string>
#include <GL/glut.h>
class IView
{
public:
    virtual std::string getName() = 0;
    virtual void init() = 0;

    virtual void onEnter() = 0;
    virtual void render() = 0;
    virtual void idle() = 0;
    virtual void timer() = 0;
    virtual void onKey(unsigned char key, int x, int y) = 0;
    virtual void onMouse(int btn, int state, int x, int y) = 0;
    virtual void onMotion(GLsizei x, GLsizei y) = 0;
    virtual void onLeave() = 0;

    virtual ~IView(){};
};