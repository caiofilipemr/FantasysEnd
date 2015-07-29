#ifndef INVENTINTERFACE_H
#define INVENTINTERFACE_H

#include <QPainter>
#include "Colision/rectangle.h"
#include "Mouse/mouse.h"
#include "Enums.h"
#include "Interface/Inventory/messagebox.h"
#include "Character/Player/player.h"
#include "chest.h"
#include "Interface/Write/write.h"

class InventoryGUI
{
private:
    static const int inv_i, inv_j, chest_i;
    int x_mouse, y_mouse, width, height, x, y, widthGUI, heightGUI, number_item[2], row_item, row_command, squary_width, squary_height, margin_width;
    Rectangle *inv, *chest, *weapon, *shield, *armor;
    ButtonCursor cur_click;
    QPixmap *squary, *back;
    MessageBox *messagebox;
    bool message, is_row_command;
    Player *player;
    Chest *chestrandom;
    QPainter *obj;
    QString action_message;
    InventorySelection current_IS;
    vector<string> commands;
    void showInfos(Item *show_item);

public:
    InventoryGUI(int width, int height, int widthGUI, int heightGUI, Player *player, QPainter *obj);

    void setCursor(int x, int y, ButtonCursor click);
    int getRowItem();
    InventorySelection getInventorySelection();
    int getRowCommand();
    bool isRowCommand();
    void draw();
    void setPlayer(Player * player) { this->player = player; }
    void setChest(Chest * new_chest);
    void setCommands(vector<string> new_commands);
    void clear();
    void clearCursor();

    int takeItemChest();
};

#endif // INVENTINTERFACE_H
