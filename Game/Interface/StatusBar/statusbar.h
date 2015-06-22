#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "Interface/Write/write.h"

class StatusBar
{
    static const int x, y, width, height, sb_limit, sb_mod;
    static int sb_cont;
public:

    static void draw(QPainter * painter, int str, int agi, int itl, int dam, int gua);
    static void reset();
};

#endif // STATUSBAR_H
