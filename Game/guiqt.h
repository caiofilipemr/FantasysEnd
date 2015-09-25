#ifndef GUIQT_H
#define GUIQT_H

#include "engine.h"
#include "Interface/Inventory/inventinterface.h"
#include "Mouse/mouse.h"
#include "Interface/Bar/bar.h"
#include "Interface/Write/write.h"
#include "Interface/mainmenu.h"

class GUIQT : public GUI
{
private:
    void setMoveMapDirection(Direction dir, int &column, int &row, int &cont_frames, int &limit);
    void drawHUD();
protected:
    QPainter * painter;
    QPixmap bg_battle, cursor_battle;
    const QPixmap bg_black;
    InventoryGUI *inventory;
    int selected_option, battle_delay_cont;
    QString battle_text;
    Exceptions mensage_type;
    bool text_right;
    static const int size_x, size_y, range_i, range_j, pix_per_tile, n_battle_options, width_options[4], text_position[2];
public:
    static const int battle_delay;

    GUIQT();
    ~GUIQT();

    //Draw
    void drawMap();
    void drawInventory();
    void drawBattle();
    void drawBrokenStone();
    void drawGameOver();
    void drawMainMenu();
    void drawPauseScreen();
    void drawStatusBar();
    void drawTransictionMapBattle(int px_to_black);
    void drawTutorial();

    //Set
    void setDrawPlayer(Player * new_draw_player);
    void setDrawMap(Map * new_draw_map);
    void setDrawMobs(std::vector<Monster *> * new_draw_mobs);
    void setQPainter(QPainter * new_painter);

    //Battle
    bool moveCursorBattle(Direction dir);
    BattleOptions getSelectedOptionBattle();
    void resetSelectedOption();
    void battleDelayCont();
    bool isBattleDelay();
    void setBattleText(Exceptions type, QString new_battle_text, bool new_text_right = true);
    void setBattleText(Exceptions type, bool new_text_right = true);

    //Main Menu
    bool moveCursorMM(Direction dir);
    PlayerClass getSelectedOptionMM();
    void MMDelayCont();
    bool isMMDelay();

    //Status Bar
    void resetStatusBar();

    //Inventory
    void setCursor(int x, int y, ButtonCursor button);
    void setChest(Chest * new_chest);
    int takeItemChest();
    int rowItemChest();
    int rowCommand();
    InventorySelection currentInventorySelected();
    void setCommands(vector<string> commands);
    bool isRowCommand();
    void clearCursor();
    void clearInventory();
};

#endif // GUIQT_H
