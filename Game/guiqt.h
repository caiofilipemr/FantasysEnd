#ifndef GUIQT_H
#define GUIQT_H

#include "engine.h"
#include "Interface/Inventory/inventinterface.h"
#include "Mouse/mouse.h"
#include "Interface/Bar/bar.h"
#include <QPainter>
#include <QPixmap>

class GUIQT : public GUI, public Mouse
{
private:
    void setMoveMapDirection(Direction dir, int &column, int &row, int &cont_frames, int &limit);
    void drawHUD();
protected:
    QPainter * painter;
    InventInterface *inventory;
    QPixmap bg_battle, cursor_battle;
    int *width_options, selected_option, battle_delay_cont;
    QString battle_text;
    QColor battle_text_color;
    bool text_right;

    static const int size_x, size_y, range_i, range_j, pix_per_tile, n_battle_options, text_position[2];
public:
    static const int battle_delay;

    GUIQT();
    ~GUIQT();
    void drawMap(/*Player * draw_player, Map *draw_map*/);
    void drawInventory();
    void drawBattle();
    void drawBrokenStone();
    void drawGameOver();

    void setDrawPlayer(Player * new_draw_player);
    void setDrawMap(Map * new_draw_map);
    void setDrawMobs(std::vector<Monster *> * new_draw_mobs);
    void setQPainter(QPainter * new_painter);
    void setCursor(int x, int y);
    int getIndexItemInventory();
    bool moveCursorBattle(Direction dir);
    BattleOptions getSelectedOption();
    void resetSelectedOption();
    void battleDelayCont();
    bool isBattleDelay();
    void setBattleText(QString new_battle_text, QColor color = Qt::white, bool new_text_right = true);
    void rightButton();
    void leftButton();
    bool messageColision();
};

#endif // GUIQT_H
