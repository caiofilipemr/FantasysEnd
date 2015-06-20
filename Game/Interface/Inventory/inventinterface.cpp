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
  squary = new QPixmap("Inventory/squary_press.png");
  back = new QPixmap("Inventory/inventory.png");
  inv = new Rectangle(width*0.503 + x, height*0.25 + y, width*0.467, height*0.4505);
  chest = new Rectangle(width*0.503 + x, height*0.811 + y, width*0.467, height*0.1441);
  message = current = false;
  chestNULL();
}

void InventInterface::setCursor(int x, int y)
{
  this->x_mouse = x;
  this->y_mouse = y;
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

void InventInterface::chestNULL()
{
    chestrandom = NULL;
}

void InventInterface::setChest(Chest *chest)
{
    chestrandom = chest;
}

InventInterface::~InventInterface()
{}

void InventInterface::draw(QPainter *obj)
{
  obj->drawPixmap(0, 0, widthGUI, heightGUI, *(this->squary));
  obj->drawPixmap(x, y, width, height, *(this->back));

  const int margin = width*0.0078, h = height*0.144145, w = width*0.088889;
  int column = (x_mouse - inv->getX())/(w + margin), line = (y_mouse - inv->getY())/(h + margin);

  int i = 0;
  while((player->getInventory())->isItem(i)){
    try{
      obj->drawPixmap(width*0.503 + x + margin*(i%5) + 35*(i%5), height*0.25 + y + 35*(i/5) + margin*(i/5),
                      32,32,QPixmap(QString::fromStdString(player->getInventory()->getItem(i)->getImg_way())));
    }catch(const char * what){
      std::cout << what;
    }
    i++;
  }
  if (chestrandom) {
      for (int i = 0, size = chestrandom->getSize(); i < size; i++) {
          obj->drawPixmap(width*0.505 + x + margin*(i%5) + 35*(i%5), height*0.81 + y + 35*(i/5) + margin*(i/5),
                          32,32,QPixmap(QString::fromStdString(chestrandom->getItem(i)->getImg_way())));
      }
  }

  if(player->getWeapon()){
    obj->drawPixmap(width*0.397 + x, height*0.305 + y,32,32,QPixmap(QString::fromStdString(player->getWeapon()->getImg_way())));
  }
  if(player->getArmor()){
    obj->drawPixmap(width*0.397 + x, height*0.56 + y,32,32,QPixmap(QString::fromStdString(player->getArmor()->getImg_way())));
  }
  if(player->getShield()){
    obj->drawPixmap(width*0.397 + x, height*0.82 + y,32,32,QPixmap(QString::fromStdString(player->getShield()->getImg_way())));
  }

  if(inv->is_colision(x_mouse, y_mouse)){
    setNumberItemInv(line*5 + (column%5));
    if(getNumberItemInv() < player->getInventory()->size()) {
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
  chestNULL();
}

bool InventInterface::isOpen()
{
    return current;
}

bool InventInterface::positionIsItem(int x, int y)
{
    const int margin = width*0.0078, h = height*0.144145, w = width*0.088889;
    int column = (x - inv->getX())/(w + margin), line = (y - inv->getY())/(h + margin);
    if(line*5 + (column%5) < player->getInventory()->size()){
        return true;
    }
    return false;
}

void InventInterface::removeItem()
{
  player->getInventory()->removeItem(getNumberItemInv());
}

void InventInterface::equipItem()
{
    try{
        player->getInventory()->getItem(getNumberItemInv())->getCommands()[0]->doThis(*player);
    }catch(const char * what){
        std::cerr << what;
    }
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

bool InventInterface::isChest(int x, int y)
{
    return chest->is_colision(x,y);
}

void InventInterface::positionChest(int x, int y)
{
    const int margin = width*0.0078, w = width*0.088889;
    int column = (x - chest->getX())/(w + margin);
    if(chestrandom && column%5 < chestrandom->getSize()) {
        if(player->getInventory()->addItem(chestrandom->getItem(column%5)))
            chestrandom->removeItem(column%5);
        else
            cerr << "Player can't equip the item, is too heavy!Equip";
        if (!chestrandom)
            chestNULL();
    }
}

