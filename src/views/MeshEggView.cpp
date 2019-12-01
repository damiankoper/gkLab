#include "views/MeshEggView.hpp"
#include <GL/glut.h>
#include <NumericUtils.hpp>
#include <DrawingUtils.hpp>
#include "ViewEngine/ViewEngine.hpp"
MeshEggView::MeshEggView()
{
}

MeshEggView::~MeshEggView()
{
}

std::string MeshEggView::getName()
{
    return "meshEgg";
}

void MeshEggView::init()
{
}

void MeshEggView::onEnter()
{
}

void MeshEggView::render()
{
    glLoadIdentity();
    gluLookAt(5.0, 10.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
    //DrawingUtils::axis();
    glRotated(-60., 1, 0, 0);
    glRotated(eggRotation, 1, 0.5, 1);
    glTranslated(0, -5., 0);
    egg.renderMesh();
}
void MeshEggView::timer()
{
    eggRotation += 1;
    if (eggRotation > 360)
        eggRotation = 0;
    glutPostRedisplay();
}

void MeshEggView::idle()
{
}
void MeshEggView::onKey(unsigned char key, int x, int y)
{
}

void MeshEggView::onMouse(int btn, int state, int x, int y)
{
}

void MeshEggView::onMotion(GLsizei x, GLsizei y)
{
}
void MeshEggView::onLeave()
{
}