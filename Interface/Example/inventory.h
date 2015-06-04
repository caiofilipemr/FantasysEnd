#ifndef INVENTORY_H
#define INVENTORY_H

#include <QPainter>
#include "squary.h"

class Inventory
{
public:
  Inventory(int width, int height, int x, int y);
  ~Inventory();

  void setCursor(int x_mouse, int y_mouse);
  void draw(QPainter *obj);

  //Funções interessantes para Engine
  void setNumberItemInv(int number);
  void setNumberItemChest(int number);
  int getNumberItemInv();
  int getNumberItemChest();

private:
  static const int inv_i, inv_j, chest_i;
  enum{ INVENTORY, CHEST };
  int width, height, x, y, x_mouse, y_mouse, number_item[2];
  Rectangle *inv, *chest;
  QPixmap *squary, *back;

};

#endif // INVENTORY_H
