#include "views/ComplexEggView.hpp"
#include <GL/glut.h>
#include <NumericUtils.hpp>
#include <DrawingUtils.hpp>
#include "ViewEngine/ViewEngine.hpp"
#include <math.h>
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
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glLoadIdentity();
    light2.azimuth = M_PI / 4;
    light2.elevation = M_PI / 4;
    light2.rDistance = 6;
    light2.color = Color(255, 0, 0);
    light2.init(GL_LIGHT0);

    light1.azimuth = -M_PI / 3;
    light1.elevation = M_PI / 3;
    light1.rDistance = 7;
    light1.color = Color(0, 0, 255);
    light1.init(GL_LIGHT1);
    glPopMatrix();
}

void ComplexEggView::render()
{
    glLoadIdentity();
    gluLookAt(5.0, 8.0, 8.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    DrawingUtils::axis();
    light2.drawSphere();
    light1.drawSphere();
    glRotated(-60., 1, 0, 0);
    glRotated(eggRotation, 1, 0, 0);
    glTranslated(0, -5., 0);
    glScaled(0.8, 0.8, 0.8);
    glPointSize(10.);
    texture.apply();
    egg.renderComplex();
}
void ComplexEggView::timer()
{
    eggRotation += 0.5;
    //    light2.azimuth += 0.01;
    light2.elevation += 0.01;
    light2.calcPosition();

    //light1.azimuth += 0.01;
    light1.elevation += 0.02;
    light1.calcPosition();
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
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
}