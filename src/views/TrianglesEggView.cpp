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
    gluLookAt(5.0, 10.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
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
}

void TrianglesEggView::onMouse(int btn, int state, int x, int y)
{
}

void TrianglesEggView::onMotion(GLsizei x, GLsizei y)
{
}
void TrianglesEggView::onLeave()
{
}