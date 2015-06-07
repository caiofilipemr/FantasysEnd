#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "colision.h"

class Rectangle : public Colision
{
public:
  Rectangle(int x, int y, int w, int h);
  ~Rectangle();
  bool is_colision(int x_mouse, int y_mouse) const;
  int getW();
  int getH();

protected:
  int w, h;
};

#endif // RECTANGLE_H
