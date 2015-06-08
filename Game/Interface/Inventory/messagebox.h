#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QPainter>
#include "Enums.h"
#include "Colision/rectangle.h"
#include "Mouse/mouse.h"

class MessageBox : public Mouse{
public:

  MessageBox();
  ~MessageBox();
  void setCursor(int x, int y);
  void draw(QPainter* painter);
  void setPosition(int x, int y);

private:
  QPixmap *back, *squary;
  Rectangle *rect;
  int x, y;
};

#endif // MESSAGEBOX_H
