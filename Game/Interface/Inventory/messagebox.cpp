#include "messagebox.h"
#include <iostream>

MessageBox::MessageBox(int x, int y) : x(x), y(y)
{
  back = new QPixmap("Inventory/Message/back.png");
  squary = new QPixmap("Inventory/Message/squary_press.png");
  rect = new Rectangle(x, y, 76, 76);
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
  painter->drawPixmap(x, y, 76, 76, *back);
  if(y_mouse - rect->getY() < rect->getH()/2 && y_mouse - rect->getY() != 0){
    painter->drawPixmap(x, y, 76, 38, *squary);
  }else{
    painter->drawPixmap(x, y + 38, 76, 38, *squary);
  }
  std::cerr << "Entrou!!!";
}

void MessageBox::setPosition(int x, int y)
{
  this->x = x;
  this->y = y;
}

bool MessageBox::isColision()
{
  return rect->is_colision(x_mouse, y_mouse);
}
