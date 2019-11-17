#include "views/DotEggView.hpp"
#include <GL/glut.h>
#include <NumericUtils.hpp>
#include <DrawingUtils.hpp>
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
    //DrawingUtils::axis();
    glRotated(30., 1, 0, 0);
    glRotated(eggRotation, 0, 1, 0);
    glTranslated(0, -5., 0);
    glPointSize(5.);
    egg.renderPoints();
    egg.renderMesh();
}
void DotEggView::timer()
{
    eggRotation += 1;
    if (eggRotation > 360)
        eggRotation = 0;
    glutPostRedisplay();
}

void DotEggView::idle()
{
}

void DotEggView::onLeave()
{
}