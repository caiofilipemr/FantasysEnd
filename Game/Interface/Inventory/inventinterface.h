#ifndef INVENTINTERFACE_H
#define INVENTINTERFACE_H

#include <QPainter>
#include "Colision/rectangle.h"
#include "Mouse/mouse.h"
#include "Enums.h"
#include "Interface/Inventory/messagebox.h"

class InventInterface: public Mouse
{
public:
  InventInterface(int width, int height, int widthGUI, int heightGUI);
  ~InventInterface();

  void setCursor(int x, int y);
  void draw(QPainter *obj);
  void isMessage();
  void notMessage();
  bool messageColision();
  void newMessage();

  //Funções interessantes para Engine
  void setNumberItemInv(int number);
  void setNumberItemChest(int number);
  int getNumberItemInv();
  int getNumberItemChest();

private:
  static const int inv_i, inv_j, chest_i;
  enum{ INVENTORY, CHEST };
  int width, height, x, y, widthGUI, heightGUI, number_item[2];
  Rectangle *inv, *chest;
  QPixmap *squary, *back;
  MessageBox *messagebox;
  bool message;
};

#endif // INVENTINTERFACE_H
