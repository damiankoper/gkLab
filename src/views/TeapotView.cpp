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
}

void TeapotView::onEnter()
{
    light1.position[0] = 10;
    light1.color = Color(0, 0, 255);
    light1.init(GL_LIGHT0);
    light1.position[0] = -10;
    light2.color = Color(255, 0, 0);
    light2.init(GL_LIGHT1);
}

void TeapotView::render()
{
    char *text = "Damian Koper";
    glLoadIdentity();
    gluLookAt(eye.x + center.x, eye.y + center.y, eye.z + center.z, center.x, center.y, center.z, 0.0, 0.0, 1.0);
    teapotMaterial.apply();
    light1.drawSphere();
    light2.drawSphere();
    DrawingUtils::text(5, 5, GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char *)text);
    DrawingUtils::axis();
    glPushMatrix();
    glRotated(xRotate, 1.0, 0.0, 0.0);
    glRotated(zRotate, 0.0, 0.0, 1.0);
    glScalef(scale, scale, scale);
    glColor3f(0.0f, 1.0f, 1.0f);
    glutSolidTeapot(3.);
    glPopMatrix();
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
        mode = Mode::cam;
        break;
    case 'm':
        mode = Mode::model;
        break;
    case 'l':
        mode = Mode::light;
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
    case 'r':
        light1.color.r += 10;
        break;
    case 'f':
        light1.color.r -= 10;
        break;
    case 't':
        light1.color.g += 10;
        break;
    case 'g':
        light1.color.g -= 10;
        break;
    case 'y':
        light1.color.b += 10;
        break;
    case 'h':
        light1.color.b -= 10;
        break;
    }
    light1.calcColor();
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
        switch (mode)
        {
        case Mode::model:
            zRotate += x - lastLeftPos[0];
            xRotate += y - lastLeftPos[1];
            zRotate = (int)zRotate % 360;
            xRotate = (int)xRotate % 360;
            break;
        case Mode::cam:
            azimuth += (x - lastLeftPos[0]) * 0.01;
            elevation += (y - lastLeftPos[1]) * 0.01;
            if (elevation >= M_PI / 2)
                elevation = M_PI / 2 - 0.0001;
            if (elevation <= -M_PI / 2)
                elevation = -M_PI / 2 + 0.0001;
            break;
        case Mode::light:
            light1.azimuth += (x - lastLeftPos[0]) * 0.01;
            light1.elevation += (y - lastLeftPos[1]) * 0.01;
            if (light1.elevation >= M_PI / 2)
                light1.elevation = M_PI / 2 - 0.0001;
            if (light1.elevation <= -M_PI / 2)
                light1.elevation = -M_PI / 2 + 0.0001;
            break;
        }

        lastLeftPos[0] = x;
        lastLeftPos[1] = y;
    }
    if (rightPressed)
    {
        switch (mode)
        {
        case Mode::model:
            scale += (y - lastRightPos[1]) * 0.01;
            break;
        case Mode::cam:
            rDistance += (y - lastRightPos[1]) * 0.1;
            break;
        case Mode::light:
            light1.rDistance += (y - lastRightPos[1]) * 0.1;
            light2.rDistance += (y - lastRightPos[1]) * 0.1;
            break;
        }
        lastRightPos[0] = x;
        lastRightPos[1] = y;
    }
    switch (mode)
    {
    case Mode::cam:
    case Mode::light:
        eye.x = rDistance * cos(azimuth) * cos(elevation);
        eye.y = rDistance * sin(azimuth) * cos(elevation);
        eye.z = rDistance * sin(elevation);
        light1.calcPosition();
        light2.calcPosition();
        break;
    }
}

void TeapotView::onLeave()
{
}