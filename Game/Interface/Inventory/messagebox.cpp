#include "messagebox.h"

MessageBox::MessageBox()
{
  back = new QPixmap("Inventory/Message/back.png");
  squary = new QPixmap("Inventory/Message/squary_press.png");
}

MessageBox::~MessageBox()
{
}

void MessageBox::setCursor(int x, int y)
{
  x_mouse = x;
  y_mouse = y;
}

void MessageBox::draw(QPainter* painter)
{
  if(rect->is_colision(x,y)){
    painter->drawPixmap(x, y, 76, 76, *back);
    if(rect->getY() - y < rect->getH()/2){
      painter->drawPixmap(x, y, 76, 38, *squary);
    }else{
      painter->drawPixmap(x, y + 38, 76, 38, *squary);
    }
  }
}

void MessageBox::setPosition(int x, int y)
{
  this->x = x;
  this->y = y;
  rect = new Rectangle(x, y, 76, 76);
}
