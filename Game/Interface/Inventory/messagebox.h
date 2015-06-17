#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QPainter>
#include "Enums.h"
#include "Colision/rectangle.h"
#include "Mouse/mouse.h"
#include "Character/Player/player.h"

class MessageBox : public Mouse{
public:

  MessageBox(int x, int y, Player* player);
  ~MessageBox();
  void setCursor(int x, int y);
  void draw(QPainter* painter, int x, int y);
  void setPosition(int x, int y);
  bool isColision();
  void isEquipUse();

private:
  QPixmap *back, *squary;
  Rectangle *rect;
  Player *player;
  int x, y;
};

#endif // MESSAGEBOX_H
