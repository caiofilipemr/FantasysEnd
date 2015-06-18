#include "messagebox.h"
#include <iostream>

MessageBox::MessageBox(int x, int y, Player *player) : x(x), y(y), player(player)
{
  back = new QPixmap("Inventory/Message/back.png");
  squary = new QPixmap("Inventory/Message/squary_press.png");
  rect = new Rectangle(x, y, 76, 76);
  current = true;
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
  setCursor(x,y);
  painter->drawPixmap(x, y, 76, 76, *back);
  if(y_mouse - rect->getY() < rect->getH()/2 && y_mouse - rect->getY() != 0){
    painter->drawPixmap(x, y, 76, 38, *squary);

  }else if(y_mouse - rect->getY() != 0){
    painter->drawPixmap(x, y + 38, 76, 38, *squary);
  }
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

bool MessageBox::isColision(int x, int y)
{
    return rect->is_colision(x,y);
}

doThis MessageBox::Click(int x, int y)
{
  //Olha que zoado
  //y_mouse - y deveria dar positivo
  //mas, no qt fica negativo
  //prova... o x_mouse - x fica positvo
  if(y - y_mouse < 76/2 && x_mouse - x < 76/2){
    return EQUIP_USE;
  }else{
    return DROP;
  }
}

bool MessageBox::isOpen()
{
    return current;
}

void MessageBox::on()
{
    current = true;
}

void MessageBox::off()
{
    current = false;
}
