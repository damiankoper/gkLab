#include "views/TrianglesEggView.hpp"
#include <GL/glut.h>
#include <NumericUtils.hpp>
#include <DrawingUtils.hpp>
#include "ViewEngine/ViewEngine.hpp"
TrianglesEggView::TrianglesEggView()
{
}

TrianglesEggView::~TrianglesEggView()
{
}

std::string TrianglesEggView::getName()
{
    return "trianglesEgg";
}

void TrianglesEggView::init()
{
}

void TrianglesEggView::onEnter()
{
}

void TrianglesEggView::render()
{
    glLoadIdentity();
    DrawingUtils::axis();
    glRotated(-60., 1, 0, 0);
    glRotated(eggRotation, 1, 1, 0.5);
    glTranslated(0, -5., 0);
    glPointSize(10.);
    egg.renderTriangles();
}
void TrianglesEggView::timer()
{
    eggRotation += 1;
    if (eggRotation > 360)
        eggRotation = 0;
    glutPostRedisplay();
}

void TrianglesEggView::idle()
{
}

void TrianglesEggView::onKey(unsigned char key, int x, int y)
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
    }
}
void TrianglesEggView::onLeave()
{
}