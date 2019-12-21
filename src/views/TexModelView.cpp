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
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
}

void TexModelView::render()
{
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    DrawingUtils::axis();
    glPushMatrix();
    glRotated(eggRotation, 0, 0, 1);
    glPointSize(10.);
    texture1.apply();
    texModel.renderTriangles();
    glPopMatrix();
    glRotated(eggRotation+180, 0, 0, 1);
    glScaled(0.5,0.5,0.5);
    texture2.apply();
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
    glDisable(GL_CULL_FACE);
}