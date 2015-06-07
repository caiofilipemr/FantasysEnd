#include "messagebox.h"

MessageBox::MessageBox()
{
  back = new QPixmap();
  button[PRESS] = new QPixmap();
  button[RELEASE] = new QPixmap();

}

MessageBox::~MessageBox()
{
}

void MessageBox::setCursor(int x, int y)
{
  x_mouse = x;
  y_mouse = y;
}

