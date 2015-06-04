#include "colision.h"

Colision::Colision(int x, int y):
  x(x), y(y)
{}

Colision::~Colision()
{}

int Colision::getX()
{
  return x;
}

int Colision::getY()
{
  return y;
}

