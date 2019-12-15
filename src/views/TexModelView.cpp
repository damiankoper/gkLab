#include "views/TexModelView.hpp"
#include <GL/glut.h>
#include <NumericUtils.hpp>
#include <DrawingUtils.hpp>
#include "ViewEngine/ViewEngine.hpp"
TexModelView::TexModelView()
{
}

TexModelView::~TexModelView()
{
}

std::string TexModelView::getName()
{
    return "texModel";
}

void TexModelView::init()
{
}

void TexModelView::onEnter()
{
    glEnable(GL_TEXTURE_2D);
}

void TexModelView::render()
{
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    DrawingUtils::axis();
    glRotated(eggRotation, 0, 0, 1);
    glPointSize(10.);
    texture.apply();
    texModel.renderTriangles();
}
void TexModelView::timer()
{
    eggRotation += 1;
    if (eggRotation > 360)
        eggRotation = 0;
    glutPostRedisplay();
}

void TexModelView::idle()
{
}
void TexModelView::onKey(unsigned char key, int x, int y)
{
}

void TexModelView::onMouse(int btn, int state, int x, int y)
{
}

void TexModelView::onMotion(GLsizei x, GLsizei y)
{
}
void TexModelView::onLeave()
{
    glDisable(GL_TEXTURE_2D);
}