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
using namespace std;

void changeSize(GLsizei horizontal, GLsizei vertical)
{
  GLfloat AspectRatio;
  if (vertical == 0) // Zabezpieczenie przed dzieleniem przez 0
    vertical = 1;
  glViewport(0, 0, horizontal, vertical);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  AspectRatio = (GLfloat)horizontal / (GLfloat)vertical;
  if (horizontal <= vertical)
    glOrtho(-7.5, 7.5, -7.5 / AspectRatio, 7.5 / AspectRatio, 10.0, -10.0);
  else
    glOrtho(-7.5 * AspectRatio, 7.5 * AspectRatio, -7.5, 7.5, 10.0, -10.0);
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
  glutCreateWindow("Lab 2");

  ViewEngine::g().add(new TeapotView());
  ViewEngine::g().add(new DotEggView());
  ViewEngine::g().add(new MeshEggView());
  ViewEngine::g().add(new TrianglesEggView());
  ViewEngine::g().add(new ComplexEggView());
  ViewEngine::g().setCurrent("complexEgg");

  glutReshapeFunc(changeSize);
  glutMainLoop();
  return 0;
}