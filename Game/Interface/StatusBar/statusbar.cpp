#include "statusbar.h"

const int StatusBar::x = 10 * 32;
const int StatusBar::y = 0;
const int StatusBar::width = 5 * 32;
const int StatusBar::height = 11 * 32;

void StatusBar::draw(QPainter *painter, int str, int agi, int itl)
{
    int division = height / 3;
    painter->drawPixmap(x, y, width, height, QPixmap("Inventory/squary_press.png"));
    Write::writeText("AGILITY " + QString::number(agi), x, y, width, division, painter);
    Write::writeText("STRENGHT " + QString::number(str), x, y + division, width, division, painter);
    Write::writeText("INTELLIGENCE " + QString::number(itl), x, y + division * 2, width, division, painter);
    painter->drawPixmap(x, y, width, height, QPixmap("Inventory/squary_press.png"));
}

