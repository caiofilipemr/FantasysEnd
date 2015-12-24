#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QPainter>
#include "Enums.h"
#include "Colision/rectangle.h"
#include "Mouse/mouse.h"
#include "Character/Player/player.h"
#include "Interface/Write/write.h"

class MessageBox : public Mouse{
public:

  MessageBox(int x, int y, Player* player);
  ~MessageBox();
  void setCursor(int x, int y);
  void draw(QPainter* painter, vector<string> commands, Rectangle mainWindow);
  void setPosition(int x, int y);
  bool isColision();
  bool isColision(int x, int y);
  doThis Click(int x, int y);
  bool isOpen();
  void on();
  void off();
  int getRowCommand();

private:
  QPixmap *top, *middle, *bottom, *squary;
  Rectangle *rect;
  int x, y;
  Player *player;
  bool current;
};

#endif // MESSAGEBOX_H
