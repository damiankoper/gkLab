#include "Light.hpp"
#include <math.h>
Light::Light()
{
}

Light::~Light()
{
}

void Light::init(int n)
{
  this->n = n;
  calcColor();
  calcPosition();

  glLightf(n, GL_CONSTANT_ATTENUATION, constant);
  glLightf(n, GL_LINEAR_ATTENUATION, linear);
  glLightf(n, GL_QUADRATIC_ATTENUATION, quadratic);

  glEnable(n);
}

void Light::calcPosition()
{
  position[0] = rDistance * cos(azimuth) * cos(elevation);
  position[1] = rDistance * sin(azimuth) * cos(elevation);
  position[2] = rDistance * sin(elevation);
  glLightfv(n, GL_POSITION, position);
}

void Light::calcColor()
{
  ambient[0] = color.r / 255. * 0.3;
  ambient[1] = color.g / 255. * 0.3;
  ambient[2] = color.b / 255. * 0.3;
  diffuse[0] = color.r / 255.;
  diffuse[1] = color.g / 255.;
  diffuse[2] = color.b / 255.;
  specular[0] = color.r / 255.;
  specular[1] = color.g / 255.;
  specular[2] = color.b / 255.;
  glLightfv(n, GL_AMBIENT, ambient);
  glLightfv(n, GL_DIFFUSE, diffuse);
  glLightfv(n, GL_SPECULAR, specular);
}

void Light::drawSphere()
{
  glPushMatrix();
  glTranslated(position[0], position[1], position[2]);
  color.apply();
  glutSolidSphere(position[3] * 0.3, 30, 30);
  glPopMatrix();
}