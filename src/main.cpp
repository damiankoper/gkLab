#include <GL/glut.h>
#include <time.h>
#include <random>
#include <queue>
using namespace std;

unsigned char randChar()
{
  return rand() % 256;
}

void randColor()
{
  glColor3ub(0, randChar(), 0);
}

void rect(float dx, float dy, float a)
{
  glBegin(GL_TRIANGLES);
  randColor();
  glVertex2f(-a / 2 + dx, -a / 2 + dy);
  randColor();
  glVertex2f(a / 2 + dx, -a / 2 + dy);
  randColor();
  glVertex2f(-a / 2 + dx, a / 2 + dy);

  randColor();
  glVertex2f(a / 2 + dx, a / 2 + dy);
  randColor();
  glVertex2f(-a / 2 + dx, a / 2 + dy);
  randColor();
  glVertex2f(a / 2 + dx, -a / 2 + dy);
  glEnd();
}



void carpet(int levels, float a, float distort = 0, float dx = 0, float dy = 0)
{
  if (levels != 0)
  {
    a = a / 3;
    carpet(levels - 1, a, distort, dx - a, dy - a);
    carpet(levels - 1, a, distort, dx, dy - a);
    carpet(levels - 1, a, distort, dx + a, dy - a);
    carpet(levels - 1, a, distort, dx - a, dy);
    carpet(levels - 1, a, distort, dx + a, dy);
    carpet(levels - 1, a, distort, dx - a, dy + a);
    carpet(levels - 1, a, distort, dx, dy + a);
    carpet(levels - 1, a, distort, dx + a, dy + a);
  }
  else
  {
    float shiftX = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / distort)) - distort / 2;
    float shiftY = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / distort)) - distort / 2;
    rect(dx - shiftX, dy - shiftY, a);
    glFlush();
    int xd = 2;
  }
}

struct CarpetLevelData
{
  int level;
  float a;
  float dx = 0;
  float dy = 0;
};

void carpetIt(int levels, float a, float distort = 0)
{
  queue<CarpetLevelData> q = queue<CarpetLevelData>();
  q.push({levels, a});

  while (!q.empty())
  {
    CarpetLevelData data = q.front();

    if (data.level > 0)
    {
      data.a = data.a / 3;
      q.push({data.level - 1, data.a, data.dx - data.a, data.dy - data.a});
      q.push({data.level - 1, data.a, data.dx, data.dy - data.a});
      q.push({data.level - 1, data.a, data.dx + data.a, data.dy - data.a});
      q.push({data.level - 1, data.a, data.dx - data.a, data.dy});
      q.push({data.level - 1, data.a, data.dx + data.a, data.dy});
      q.push({data.level - 1, data.a, data.dx - data.a, data.dy + data.a});
      q.push({data.level - 1, data.a, data.dx, data.dy + data.a});
      q.push({data.level - 1, data.a, data.dx + data.a, data.dy + data.a});
    }
    else
    {
      float shiftX = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / distort)) - distort / 2;
      float shiftY = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / distort)) - distort / 2;
      rect(data.dx - shiftX, data.dy - shiftY, data.a);
    }

    q.pop();
  }
}

//Drawing funciton
void draw(void)
{
  //Background color
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  carpet(3, 1.f, 0.05f);
  //carpetIt(4, 1.8f, 0.05f);

  //Draw order
  glFlush();
}

//Main program
int main(int argc, char **argv)
{
  srand(time(NULL));
  glutInit(&argc, argv);

  //Simple buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(50, 25);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Lab1");

  //Call to the drawing function
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}