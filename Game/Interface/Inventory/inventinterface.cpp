#include "inventinterface.h"
#include <iostream>

const int InventInterface::inv_i = 3;
const int InventInterface::inv_j = 5;
const int InventInterface::chest_i = 5;

InventInterface::InventInterface(int width, int height, int widthGUI, int heightGUI, Player *player):
  width(width), height(height), x(widthGUI/2 - width/2), y(heightGUI/2 - height/2),
  widthGUI(widthGUI), heightGUI(heightGUI), player(player)
{
  messagebox = new MessageBox(0, 0, player);
  list = new Inventory();
  squary = new QPixmap("Inventory/squary_press.png");
  back = new QPixmap("Inventory/inventory.png");
  inv = new Rectangle(width*0.503 + x, height*0.25 + y, width*0.467, height*0.4505);
  chest = new Rectangle(width*0.503 + x, height*0.811 + y, width*0.467, height*0.1441);
  message = current = false;
}

void InventInterface::setCursor(int x, int y)
{
  this->x_mouse = x;
  this->y_mouse = y;
//  if(message) {
//    messagebox->setCursor(x,y);
//  }
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

void InventInterface::setPlayer(Player *player)
{
    this->player = player;
}

Inventory *InventInterface::getInventory()
{
    return list;
}

InventInterface::~InventInterface()
{}

void InventInterface::draw(QPainter *obj)
{
  obj->drawPixmap(0, 0, widthGUI, heightGUI, *(this->squary));
  obj->drawPixmap(x, y, width, height, *(this->back));

  const int margin = width*0.0078, h = height*0.144145, w = width*0.088889;
  int column = (x_mouse - inv->getX())/(w + margin), line = (y_mouse - inv->getY())/(h + margin);

  Inventory *inven = player->getInventory();
  int i = 0;
  while((player->getInventory())->isItem(i)){
    try{
      obj->drawPixmap(width*0.503 + x + margin*(i%5) + 35*(i%5), height*0.25 + y + 35*(i/5) + margin*(i/5),
                      32,32,QPixmap(QString::fromStdString(inven->getItem(i)->getImg_way())));
    }catch(const char * what){
      std::cout << what;
    }
    i++;
  }

  if(inv->is_colision(x_mouse, y_mouse)){
    setNumberItemInv(line*5 + (column%5));
    if(getNumberItemInv() < list->size()) {
        obj->drawPixmap(column*w + inv->getX() + margin*column, line*h + inv->getY() + line*margin, w, h, *squary);
    }

  }else if(chest->is_colision(x_mouse, y_mouse)){
    obj->drawPixmap(column*w + chest->getX() + margin*column, chest->getY(), w, h, *squary);
    setNumberItemChest(column%5);
  }
}

void InventInterface::on()
{
  current = true;
}

void InventInterface::off()
{
  current = false;
}

bool InventInterface::isOpen()
{
    return current;
}

void InventInterface::removeItem()
{
  //Por enquanto
  list->removeItem(getNumberItemInv());
}

void InventInterface::drawMessage(QPainter *obj)
{
    if(message) {
      if(inv->is_colision(x_mouse, y_mouse)){
        messagebox->draw(obj);
      }else if(chest->is_colision(x_mouse, y_mouse)){
        //Primeiro arrumar chest
        //messagebox->draw(obj, getNumberItemChest());
      }
    }
}

void InventInterface::isMessage()
{
//  if(messagebox == NULL) {
//    delete messagebox;
//  }
  if((chest->is_colision(x_mouse, y_mouse) || inv->is_colision(x_mouse, y_mouse)) && player->getInventory()->isItem(getNumberItemInv())) {
    message = true;
  }
}

void InventInterface::notMessage()
{
  message = false;
}

bool InventInterface::messageColision()
{
  if(messagebox->isColision())
    return true;
  return false;
}

void InventInterface::newMessage()
{
    messagebox = new MessageBox(x_mouse, y_mouse, player);
}

bool InventInterface::invColision(int x, int y)
{
    return inv->is_colision(x,y);
}
