#include "inventinterface.h"
#include <iostream>

const int InventInterface::inv_i = 3;
const int InventInterface::inv_j = 5;
const int InventInterface::chest_i = 5;

InventInterface::InventInterface(int width, int height, int widthGUI, int heightGUI):
  width(width), height(height), x(widthGUI/2 - width/2), y(heightGUI/2 - height/2),
  widthGUI(widthGUI), heightGUI(heightGUI)
{
  squary = new QPixmap("Inventory/squary_press.png");
  back = new QPixmap("Inventory/inventory.png");
  inv = new Rectangle(width*0.503 + x, height*0.25 + y, width*0.467, height*0.4505);
  chest = new Rectangle(width*0.503 + x, height*0.811 + y, width*0.467, height*0.1441);
  message = false;
  messagebox = new MessageBox();
}

void InventInterface::setCursor(int x, int y)
{
  this->x_mouse = x;
  this->y_mouse = y;
  if(message) {
    messagebox->setPosition(x,y);
  }else{
    message = false;
  }
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
  setCursor(x_mouse, y_mouse);
  obj->drawPixmap(0, 0, widthGUI, heightGUI, *(this->squary));
  obj->drawPixmap(x, y, width, height, *(this->back));

  const int margin = width*0.0078, h = height*0.144145, w = width*0.088889;
  if(inv->is_colision(x_mouse, y_mouse)){
    int column = (x_mouse - inv->getX())/(w + margin), line = (y_mouse - inv->getY())/(h + margin);
    obj->drawPixmap(column*w + inv->getX() + margin*column, line*h + inv->getY() + line*margin, w, h, *squary);

    setNumberItemInv(line*5 + (column%5));

  }else if(chest->is_colision(x_mouse, y_mouse)){

    int column = (x_mouse - chest->getX())/(w + margin);
    obj->drawPixmap(column*w + chest->getX() + margin*column, chest->getY(), w, h, *squary);

    setNumberItemChest(column%5);
    //std::cerr << getNumberItemChest();
  }

  if(message) {
    messagebox->draw(obj);
  }
}

void InventInterface::isMessage()
{
  message = true;
}

void InventInterface::notMessage()
{
  message = false;
}
