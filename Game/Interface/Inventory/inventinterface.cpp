#include "inventinterface.h"
#include <iostream>

const int InventInterface::inv_i = 3;
const int InventInterface::inv_j = 5;
const int InventInterface::chest_i = 5;

InventInterface::InventInterface(int width, int height, int x, int y):
  width(width), height(height), x(x), y(y)
{
  x_mouse = y_mouse = 0;
  squary = new QPixmap("Inventory/squary_press.png");
  back = new QPixmap("Inventory/inventory.png");
  inv = new Rectangle(181 + x, 55 + y, 168, 100);
  chest = new Rectangle(181 + x, 180 + y, 168, 32);
}

void InventInterface::setCursor(int x_mouse, int y_mouse)
{
  this->x_mouse = x_mouse;
  this->y_mouse = y_mouse;
}

void InventInterface::setNumberItemInv(int number)
{
  number_item[INVENTORY] = number;
}

void InventInterface::setNumberItemChest(int number)
{
  number_item[CHEST] = number;
}

int InventInterface::getNumberItemInv()
{
  return number_item[INVENTORY];
}

int InventInterface::getNumberItemChest()
{
  return number_item[CHEST];
}

InventInterface::~InventInterface()
{}

void InventInterface::draw(QPainter *obj)
{
  obj->drawPixmap(x, y, width, height, *(this->back));
  if(inv->is_colision(x_mouse, y_mouse)){

    const int margin = 2;
    int column = (x_mouse - inv->getX())/34, line = (y_mouse - inv->getY())/34;
    obj->drawPixmap(column*32 + inv->getX() + margin*column, line*32 + inv->getY() + line*margin, 32, 32, *squary);

    setNumberItemInv(line*5 + (column%5));
    //std::cerr << getNumberItemInv();

  }else if(chest->is_colision(x_mouse, y_mouse)){

    const int margin = 2;
    int column = (x_mouse - chest->getX())/34;
    obj->drawPixmap(column*32 + chest->getX() + margin*column, chest->getY(), 32, 32, *squary);

    setNumberItemChest(column%5);
    //std::cerr << getNumberItemChest();
  }
}
