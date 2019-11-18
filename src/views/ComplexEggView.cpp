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
    switch (key)
    {
    case '1':
        ViewEngine::g().setCurrent("teapot");
        break;
    case '2':
        ViewEngine::g().setCurrent("dotEgg");
        break;
    case '3':
        ViewEngine::g().setCurrent("meshEgg");
        break;
    case '4':
        ViewEngine::g().setCurrent("trianglesEgg");
        break;
    case '5':
        ViewEngine::g().setCurrent("complexEgg");
        break;
    }
}
void ComplexEggView::onLeave()
{
}