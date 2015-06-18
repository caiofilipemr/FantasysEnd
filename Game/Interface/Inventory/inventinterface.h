#ifndef INVENTINTERFACE_H
#define INVENTINTERFACE_H

#include <QPainter>
#include "Colision/rectangle.h"
#include "Mouse/mouse.h"
#include "Enums.h"
#include "Interface/Inventory/messagebox.h"
#include "Character/Player/player.h"

class InventInterface: public Mouse
{
public:
  InventInterface(int width, int height, int widthGUI, int heightGUI, Player *player);
  ~InventInterface();

  void setCursor(int x, int y);
  void draw(QPainter *obj);

  void on();
  void off();
  bool isOpen();
  bool positionIsItem(int x, int y);
  void removeItem();
  void equipItem(int x, int y);

  void drawMessage(QPainter *obj);
  void isMessage();
  void notMessage();
  void newMessage();

  bool invColision(int x, int y);
  bool chesColision(int x, int y);
  bool messageColision();

  void setNumberItemInv(int number);
  void setNumberItemChest(int number);
  int getNumberItemInv();
  int getNumberItemChest();
  void setPlayer(Player *player);
  Inventory *getInventory();

private:
  static const int inv_i, inv_j, chest_i;
  enum{ INVENTORY, CHEST };
  int width, height, x, y, widthGUI, heightGUI, number_item[2];
  Rectangle *inv, *chest;
  QPixmap *squary, *back, *img_inventory[15];
  MessageBox *messagebox;
  Inventory *list;
  bool message, current;
  Player* player;
};

#endif // INVENTINTERFACE_H
