#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h):
  Colision(x, y), w(w), h(h)
{}

Rectangle::~Rectangle()
{}

bool Rectangle::is_colision(int x_mouse, int y_mouse) const
{
    return x <= x_mouse && y <= y_mouse && x_mouse <= x + w && y_mouse <= y + h;
}

int Rectangle::getW()
{
  return w;
}

int Rectangle::getH(){
  return h;
}
