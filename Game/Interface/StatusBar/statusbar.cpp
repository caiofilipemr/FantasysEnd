#include "statusbar.h"

const int StatusBar::x = 10 * 32;
const int StatusBar::y = 0;
const int StatusBar::width = 5 * 32;
const int StatusBar::height = 11 * 32;

void StatusBar::draw(QPainter *painter, int str, int agi, int itl)
{
    painter->drawPixmap(x, y, width, height, "Inventory/squary_press.png");

}

