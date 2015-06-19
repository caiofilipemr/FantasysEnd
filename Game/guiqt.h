#ifndef GUIQT_H
#define GUIQT_H

#include "engine.h"
#include "Interface/Inventory/inventinterface.h"
#include "Mouse/mouse.h"
#include "Interface/Bar/bar.h"
#include "Interface/Write/write.h"
#include "Interface/mainmenu.h"

class GUIQT : public GUI, public Mouse
{
private:
    void setMoveMapDirection(Direction dir, int &column, int &row, int &cont_frames, int &limit);
    void drawHUD();
protected:
    QPainter * painter;
    InventInterface *inventory;
    QPixmap bg_battle, cursor_battle;
    int selected_option, battle_delay_cont;
    QString battle_text;
    //QColor battle_text_color;
    Exceptions mensage_type;
    bool text_right;
    const QPixmap bg_black;
    MessageBox * messageGUI;

    static const int size_x, size_y, range_i, range_j, pix_per_tile, n_battle_options, width_options[4], text_position[2];
public:
    static const int battle_delay;

    GUIQT();
    ~GUIQT();
    void drawMap(/*Player * draw_player, Map *draw_map*/);
    void drawInventory();
    void drawBattle();
    void drawBrokenStone();
    void drawGameOver();
    void drawMainMenu();
    void drawPauseScreen();

    void setDrawPlayer(Player * new_draw_player);
    void setDrawMap(Map * new_draw_map);
    void setDrawMobs(std::vector<Monster *> * new_draw_mobs);

    void drawTransictionMapBattle(int px_to_black);
    void setQPainter(QPainter * new_painter);
    void setCursor(int x, int y);
    //Tive que fazer sobrecarga de função deu erro no qt, why?
    void setCursor(int x, int y, ButtonCursor button);
    int getIndexItemInventory();
    bool moveCursorBattle(Direction dir);
    bool moveCursorMM(Direction dir);
    BattleOptions getSelectedOptionBattle();
    PlayerClass getSelectedOptionMM();
    void resetSelectedOption();
    void battleDelayCont();
    void MMDelayCont();
    bool isBattleDelay();
    bool isMMDelay();
    void setBattleText(Exceptions type, QString new_battle_text, bool new_text_right = true);
    void setBattleText(Exceptions type, bool new_text_right = true);

    bool inventoryIsOpen();
    void inventoryOn();
    void inventoryOff();
    bool messageIsOpen();
    void messageOn();
    void messageOff();
    void newMessage(int x, int y);

    void rightButton();
    void leftButton();
    bool messageColision();
    void drawMessage();
};

#endif // GUIQT_H
