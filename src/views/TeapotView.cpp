#include "views/TeapotView.hpp"
#include <GL/glut.h>
#include <NumericUtils.hpp>
#include <DrawingUtils.hpp>
#include "ViewEngine/ViewEngine.hpp"
#include <math.h>
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
    NumericUtils::glSetRandColor();
}

void TeapotView::onEnter()
{
}

void TeapotView::render()
{
    char *text = "Damian Koper";
    glLoadIdentity();
    gluLookAt(eye.x + center.x, eye.y + center.y, eye.z + center.z, center.x, center.y, center.z, 0.0, 0.0, 1.0);
    DrawingUtils::text(5, 5, GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char *)text);
    DrawingUtils::axis();
    glRotated(xRotate, 1.0, 0.0, 0.0);
    glRotated(zRotate, 0.0, 0.0, 1.0);
    glScalef(scale, scale, scale);
    glColor3f(0.0f, 1.0f, 1.0f);
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
    case 'c':
        camMode = true;
        break;
    case 'o':
        camMode = false;
        break;
    case 'w':
        center.x += 0.5;
        break;
    case 'a':
        center.y -= 0.5;
        break;
    case 's':
        center.x -= 0.5;
        break;
    case 'd':
        center.y += 0.5;
        break;
    }
}

void TeapotView::onMouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        lastLeftPos[0] = x;
        lastLeftPos[1] = y;
        leftPressed = true;
    }
    else
    {
        leftPressed = false;
    }
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        lastRightPos[0] = x;
        lastRightPos[1] = y;
        rightPressed = true;
    }
    else
    {
        rightPressed = false;
    }
}

void TeapotView::onMotion(GLsizei x, GLsizei y)
{
    if (leftPressed)
    {
        if (camMode)
        {
            zAngle += (x - lastLeftPos[0]) * 0.01;
            xyAngle += (y - lastLeftPos[1]) * 0.01;
        }
        else
        {
            zRotate += x - lastLeftPos[0];
            xRotate += y - lastLeftPos[1];
            zRotate = (int)zRotate % 360;
            xRotate = (int)xRotate % 360;
        }
        lastLeftPos[0] = x;
        lastLeftPos[1] = y;
    }
    if (rightPressed)
    {
        if (camMode)
        {
            rDistance += (y - lastRightPos[1]) * 0.1;
        }
        else
        {
            scale += (y - lastRightPos[1]) * 0.01;
        }
        lastRightPos[0] = x;
        lastRightPos[1] = y;
    }
    if (camMode)
    {
        eye.x = rDistance * cos(zAngle) * cos(xyAngle);
        eye.y = rDistance * sin(zAngle) * cos(xyAngle);
        eye.z = rDistance * sin(xyAngle);
    }
}

void TeapotView::onLeave()
{
}