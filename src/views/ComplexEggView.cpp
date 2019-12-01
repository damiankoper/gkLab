#include "views/ComplexEggView.hpp"
#include <GL/glut.h>
#include <NumericUtils.hpp>
#include <DrawingUtils.hpp>
#include "ViewEngine/ViewEngine.hpp"
ComplexEggView::ComplexEggView()
{
}

ComplexEggView::~ComplexEggView()
{
}

std::string ComplexEggView::getName()
{
    return "complexEgg";
}

void ComplexEggView::init()
{
}

void ComplexEggView::onEnter()
{
}

void ComplexEggView::render()
{
    glLoadIdentity();
    gluLookAt(5.0, 10.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
    DrawingUtils::axis();
    glRotated(-60., 1, 0, 0);
    glRotated(eggRotation, 1, 0, 0);
    glTranslated(0, -5., 0);
    glPointSize(10.);
    egg.renderComplex();
}
void ComplexEggView::timer()
{
    eggRotation += 1;
    if (eggRotation > 360)
        eggRotation = 0;
    glutPostRedisplay();
}

void ComplexEggView::idle()
{
}

void ComplexEggView::onKey(unsigned char key, int x, int y)
{
}

void ComplexEggView::onMouse(int btn, int state, int x, int y)
{
}

void ComplexEggView::onMotion(GLsizei x, GLsizei y)
{
}

void ComplexEggView::onLeave()
{
}