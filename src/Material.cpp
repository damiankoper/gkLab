#include "Material.hpp"

Material::Material()
{
}

Material::~Material()
{
}

void Material::apply()
{
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}