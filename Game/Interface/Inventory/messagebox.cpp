#include "messagebox.h"
#include <iostream>

MessageBox::MessageBox(int x, int y, Player *player) : x(x), y(y), player(player)
{
    top = new QPixmap("Inventory/Message/Top2.png");
    middle = new QPixmap("Inventory/Message/Middle2.png");
    bottom = new QPixmap("Inventory/Message/Bottom2.png");
    squary = new QPixmap("Inventory/Message/squary_press.png");
    rect = new Rectangle(x, y, top->width(), top->height() + middle->height() + bottom->height()); //Organizar
    current = true;
}

MessageBox::~MessageBox()
{
}

void MessageBox::setCursor(int x, int y)
{
  x_mouse = x;
  y_mouse = y;
}

void MessageBox::draw(QPainter* painter, vector<string> commands, Rectangle mainWindow)
{
    int size = commands.size(), i = 0;

    if ((x + 149) > mainWindow.getW()) {
        x = x - 149;
    }

    if ((y + (size * 28 + 14)) > mainWindow.getH()) {
        y = y - (size * 28 + 14);
    }

    setCursor(x, y);

    if (i < size) {
        painter->drawPixmap(x, y, 149, 29, *top);
        Write::writeText(QString::fromStdString(commands[i]), x, y + 9, 149, 24, painter);
    }
    y++;
    for (i++; i < size; i++) {
        painter->drawPixmap(x, y + (28 * i), 149, 28, *middle);
        Write::writeText(QString::fromStdString(commands[i]), x, y + 8 + (28 * i), 149, 24, painter);
    }
    painter->drawPixmap(x, y + (28 * i), 149, 13, *bottom);
}

void MessageBox::setPosition(int x, int y)
{
  this->x = x;
  this->y = y;
}

bool MessageBox::isColision()
{
    return rect->is_colision(x_mouse - x, y_mouse - y);
}

bool MessageBox::isColision(int x, int y)
{
    return rect->is_colision(x,y);
}

doThis MessageBox::Click(int x, int y)
{
  //Olha que zoado
  //y_mouse - y deveria dar positivo
  //mas, no qt fica negativo
  //prova... o x_mouse - x fica positvo
  if(y - y_mouse < 76/2 && x_mouse - x < 76/2){
    return EQUIP_USE;
  }else{
    return DROP;
  }
}

bool MessageBox::isOpen()
{
    return current;
}

void MessageBox::on()
{
    current = true;
}

void MessageBox::off()
{
    current = false;
}

int MessageBox::getRowCommand()
{
    if (!isColision()) throw "Is not colision!!!";
    return int(y_mouse - y) / 35;
}
