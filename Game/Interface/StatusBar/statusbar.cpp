#include "statusbar.h"

const int StatusBar::x = 15 * 32;
const int StatusBar::y = 0;
const int StatusBar::width = 5 * 32;
const int StatusBar::height = 11 * 32;
const int StatusBar::sb_limit = 16;
const int StatusBar::sb_mod = (x - (StatusBar::x - StatusBar::width)) / StatusBar::sb_limit;
int StatusBar::sb_cont = 0;

void StatusBar::draw(QPainter *painter, int str, int agi, int itl, int dam, int gua)
{
    int division = height / 5;
    painter->drawPixmap(x - sb_mod * sb_cont, y, width, height, QPixmap("Inventory/squary_press.png"));
    Write::writeText("AGILITY " + QString::number(agi), x - sb_mod * sb_cont, y, width, division, painter);
    Write::writeText("STRENGHT " + QString::number(str), x - sb_mod * sb_cont, y + division, width, division, painter);
    Write::writeText("INTELLIGENCE " + QString::number(itl), x - sb_mod * sb_cont, y + division * 2, width, division, painter);
    Write::writeText("DAMAGE " + QString::number(dam), x - sb_mod * sb_cont, y + division * 3, width, division, painter);
    Write::writeText("GUARD " + QString::number(gua), x - sb_mod * sb_cont, y + division * 4, width, division, painter);
    if (sb_cont < sb_limit) sb_cont++;
}

void StatusBar::reset()
{
    sb_cont = 0;
}

