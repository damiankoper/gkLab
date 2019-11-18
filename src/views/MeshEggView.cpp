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
void MeshEggView::onLeave()
{
}