#include "inventinterface.h"
#include <iostream>

const int InventInterface::inv_i = 3;
const int InventInterface::inv_j = 5;
const int InventInterface::chest_i = 5;

InventInterface::InventInterface(int width, int height, int widthGUI, int heightGUI, Player *player, QPainter *obj):
  width(width), height(height), x(widthGUI/2 - width/2), y(heightGUI/2 - height/2),
  widthGUI(widthGUI), heightGUI(heightGUI), player(player), obj(obj)
{
  messagebox = new MessageBox(0, 0, player);
  squary = new QPixmap("Inventory/squary_press.png");
  back = new QPixmap("Inventory/inventory.png");
  inv = new Rectangle(width*0.503 + x, height*0.25 + y, width*0.467, height*0.4505);
  chest = new Rectangle(width*0.503 + x, height*0.811 + y, width*0.467, height*0.1441);
  weapon = new Rectangle(width*0.397 + x, height*0.305 + y, 36, 36);
  shield = new Rectangle(width*0.397 + x, height*0.56 + y, 36, 36);
  armor = new Rectangle(width*0.397 + x, height*0.82 + y, 36, 36);
  message = current = false;
  chestNULL();
}

void InventInterface::setCursor(int x, int y)
{
  this->x_mouse = x;
  this->y_mouse = y;
    action_message.clear();
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

void InventInterface::showInfos(Item *show_item)
{
    Write::writeText(QString::fromStdString(show_item->getItemName()), 0, 0, 15 * 32, y, obj);

    Information info = show_item->getInfos();
    QString info_msg = "   ";

    for (int i = 0; i < info.getSize(); i++) {
        info_msg += QString::fromStdString(info.getInfoName(i));
        info_msg += "  ";
        info_msg += QString::number(info.getInfo(i));
        info_msg += "   ";
    }
    Write::writeText(info_msg, 0, y + height, 15 * 32, heightGUI - (y + height), obj);
}

void InventInterface::setChest(Chest *chest)
{
    chestrandom = chest;
}

InventInterface::~InventInterface()
{}

void InventInterface::draw()
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

  if (!action_message.isEmpty())
      Write::writeText(action_message, 0, y + height, 15 * 32, heightGUI - (y + height), obj);

  if(player->getWeapon()){
    obj->drawPixmap(width*0.397 + x, height*0.305 + y,32,32,QPixmap(QString::fromStdString(player->getWeapon()->getImg_way())));
    if (weapon->is_colision(x_mouse, y_mouse)) {
        obj->drawPixmap(width*0.397 + x, height*0.305 + y, 36, 36, *squary);
        showInfos(player->getWeapon());
    }
  }
  if(player->getShield()){
    obj->drawPixmap(width*0.397 + x, height*0.56 + y,32,32,QPixmap(QString::fromStdString(player->getShield()->getImg_way())));
    if (shield->is_colision(x_mouse, y_mouse)) {
        obj->drawPixmap(width*0.397 + x, height*0.56 + y, 36, 36, *squary);
        showInfos(player->getShield());
    }
  }
  if(player->getArmor()){
    obj->drawPixmap(width*0.397 + x, height*0.82 + y,32,32,QPixmap(QString::fromStdString(player->getArmor()->getImg_way())));
    if (armor->is_colision(x_mouse, y_mouse)) {
        obj->drawPixmap(width*0.397 + x, height*0.82 + y, 36, 36, *squary);
        showInfos(player->getArmor());
    }
  }

  if(inv->is_colision(x_mouse, y_mouse)){
    setNumberItemInv(line*5 + (column%5));
    if(getNumberItemInv() < player->getInventory()->size()) {
        obj->drawPixmap(column*w + inv->getX() + margin*column, line*h + inv->getY() + line*margin, w, h, *squary);

        showInfos(player->getInventory()->getItem(getNumberItemInv()));
    }

  }else if(chest->is_colision(x_mouse, y_mouse) && chestrandom){
    setNumberItemChest(column%5);
    if (getNumberItemChest() < chestrandom->getSize()) {
        obj->drawPixmap(column*w + chest->getX() + margin*column, chest->getY(), w, h, *squary);
        showInfos(chestrandom->getItem(getNumberItemChest()));

    }
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
  action_message.clear();
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
    if (chestrandom) {
        chestrandom->addItem(player->getInventory()->removeItem(getNumberItemInv()));
    }
    else {

        player->getInventory()->removeItem(getNumberItemInv());
    }
    setCursor(0, 0);
    action_message = "DROP";
}

void InventInterface::equipItem()
{
    try{
        int i = getNumberItemInv();
        setCursor(0, 0);
        action_message = QString::fromStdString(player->getInventory()->getItem(i)->getCommands()[0]->getCmdName());
        player->getInventory()->getItem(i)->getCommands()[0]->doThis(*player);
    }catch(const char * what){
        setCursor(0, 0);
      action_message = what;
    }
}

void InventInterface::drawMessage()
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

void InventInterface::positionChest(int x, int)
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

