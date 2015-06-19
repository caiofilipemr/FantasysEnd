#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "Interface/Write/write.h"

class StatusBar
{
    static const int x, y, width, height;
public:

    void draw(QPainter * painter, int str, int agi, int itl);
};

#endif // STATUSBAR_H
