#include "views/DotEggView.hpp"
#include <GL/glut.h>
#include <NumericUtils.hpp>
#include <DrawingUtils.hpp>
#include "ViewEngine/ViewEngine.hpp"
DotEggView::DotEggView()
{
}

DotEggView::~DotEggView()
{
}

std::string DotEggView::getName()
{
    return "dotEgg";
}

void DotEggView::init()
{
}

void DotEggView::onEnter()
{
}

void DotEggView::render()
{
    glLoadIdentity();
    gluLookAt(5.0, 10.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    glRotated(-60., 1, 0, 0);
    glRotated(eggRotation, 1, 1, 1);
    glTranslated(0, -5., 0);
    glPointSize(10.);
    egg.renderPoints();
}
void DotEggView::timer()
{
    eggRotation += 1;
    if (eggRotation >= 360)
        eggRotation = 0;
    glutPostRedisplay();
}

void DotEggView::idle()
{
}

void DotEggView::onKey(unsigned char key, int x, int y)
{
}

void DotEggView::onMouse(int btn, int state, int x, int y)
{
}

void DotEggView::onMotion(GLsizei x, GLsizei y)
{
}

void DotEggView::onLeave()
{
}