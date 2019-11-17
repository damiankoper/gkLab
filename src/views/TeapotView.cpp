#include "views/TeapotView.hpp"
#include <GL/glut.h>
#include <NumericUtils.hpp>
#include <DrawingUtils.hpp>
TeapotView::TeapotView()
{
}

TeapotView::~TeapotView()
{
}

std::string TeapotView::getName()
{
    return "empty";
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
}

void TeapotView::idle()
{
}

void TeapotView::onLeave()
{
}