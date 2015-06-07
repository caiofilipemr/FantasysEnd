#ifndef GUIQT_H
#define GUIQT_H

#include "engine.h"
#include <QPainter>
#include <QPixmap>

class GUIQT : public GUI
{
protected:
    QPainter * painter;

    static const int size_x, size_y, range_i, range_j, pix_per_tile;
public:
    GUIQT(/*QPainter *new_painter*/);
    void drawMap(/*Player * draw_player, Map *draw_map*/);
    void drawInventory();
    void drawBattle();
    void drawBrokenStone();
    void drawGameOver();

    void setDrawPlayer(Player * new_draw_player);
    void setDrawMap(Map * new_draw_map);
    void setDrawMobs(std::vector<Monster *> * new_draw_mobs);
    void setQPainter(QPainter * new_painter);
};

#endif // GUIQT_H
