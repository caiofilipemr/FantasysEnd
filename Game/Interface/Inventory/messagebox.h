#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QPainter>
#include "Enums.h"
#include "Colision/rectangle.h"
#include "Mouse/mouse.h"

class MessageBox: public Mouse{
public:

  MessageBox();
  ~MessageBox();
  void setCursor(int x, int y);

private:
  QPixmap *back, *button[2];
  Rectangle *del, *add, *all;

};

#endif // MESSAGEBOX_H
