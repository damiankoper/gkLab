#include "views/TeapotView.hpp"
#include <GL/glut.h>
#include <NumericUtils.hpp>
#include <DrawingUtils.hpp>
#include "ViewEngine/ViewEngine.hpp"
TeapotView::TeapotView()
{
}

TeapotView::~TeapotView()
{
}

std::string TeapotView::getName()
{
    return "teapot";
}

void TeapotView::init()
{
}

void TeapotView::onEnter()
{
}

void TeapotView::render()
{
    glLoadIdentity();
    glRotated(-10, 1.0, 1.0, 0.0);
    DrawingUtils::axis();
    NumericUtils::glSetRandColor();
    glutWireTeapot(3.);
}

void TeapotView::timer()
{
    glutPostRedisplay();
}

void TeapotView::idle()
{
}
void TeapotView::onKey(unsigned char key, int x, int y)
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
void TeapotView::onLeave()
{
}