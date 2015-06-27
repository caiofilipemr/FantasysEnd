#ifndef INVENTINTERFACE_H
#define INVENTINTERFACE_H

#include <QPainter>
#include "Colision/rectangle.h"
#include "Mouse/mouse.h"
#include "Enums.h"
#include "Interface/Inventory/messagebox.h"
#include "Character/Player/player.h"
#include "chest.h"
#include "Interface/Write/write.h"

class InventInterface : public Mouse
{
public:
  InventInterface(int width, int height, int widthGUI, int heightGUI, Player *player, QPainter *obj);
  virtual ~InventInterface();

  void setCursor(int x, int y);
  void draw();

  void on();
  void off();
  bool isOpen();
  bool positionIsItem(int x, int y);
  void removeItem();
  void equipItem();

  void drawMessage();
  void isMessage();
  void notMessage();
  void newMessage();

  bool invColision(int x, int y);
  bool isChest(int x, int y);
  void positionChest(int x, int y);
  bool chesColision(int x, int y);
  bool messageColision();

  void setNumberItemInv(int number);
  void setNumberItemChest(int number);
  int getNumberItemInv();
  int getNumberItemChest();
  void setPlayer(Player *player);
  void setChest(Chest *chest);
  void chestNULL();

private:
  static const int inv_i, inv_j, chest_i;
  enum{ INVENTORY, CHEST };
  int width, height, x, y, widthGUI, heightGUI, number_item[2];
  Rectangle *inv, *chest, *weapon, *shield, *armor;
  QPixmap *squary, *back, *img_inventory[15];
  MessageBox *messagebox;
  bool message, current;
  Player* player;
  Chest* chestrandom;
  QPainter *obj;
  QString action_message;

  void showInfos(Item *show_item);
};

#endif // INVENTINTERFACE_H
