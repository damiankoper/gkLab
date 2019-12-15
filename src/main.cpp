#include <GL/glut.h>
#include <time.h>
#include <random>
#include <queue>
#include "ViewEngine/ViewEngine.hpp"
#include "views/TeapotView.hpp"
#include "views/DotEggView.hpp"
#include "views/MeshEggView.hpp"
#include "views/TrianglesEggView.hpp"
#include "views/ComplexEggView.hpp"
#include "views/TexModelView.hpp"
using namespace std;

void changeSize(GLsizei horizontal, GLsizei vertical)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, (float)horizontal / (float)vertical, 1.0, 30.0);
  glViewport(0, 0, horizontal, vertical);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

//Main program
int main(int argc, char **argv)
{
  srand(time(NULL));
  glutInit(&argc, argv);

  //Simple buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(50, 25);
  glutInitWindowSize(1280, 720);
  glutCreateWindow("Lab 5");
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

  ViewEngine::g().setKeyboardRouter([](unsigned char key) {
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
    case '6':
      ViewEngine::g().setCurrent("texModel");
      break;
    default:
      return false;
    }
    return true;
  });

  ViewEngine::g().add(new TeapotView());
  ViewEngine::g().add(new DotEggView());
  ViewEngine::g().add(new MeshEggView());
  ViewEngine::g().add(new TrianglesEggView());
  ViewEngine::g().add(new ComplexEggView());
  ViewEngine::g().add(new TexModelView());
  ViewEngine::g().setCurrent("texModel");

  glutReshapeFunc(changeSize);
  glutMainLoop();
  return 0;
}