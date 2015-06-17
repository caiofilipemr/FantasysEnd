#ifndef MAINMENU_H
#define MAINMENU_H

#include <QPixmap>
#include "Interface/Bar/bar.h"
#include "Enums.h"
#include "macros.h"

class MainMenu
{
protected:
    static const char * img_way[10];
    static int width, height;
    static int selected_option, n_class_options, delay_cont, max_delay, back_selected;
    static int att_ini_class[6][3];
    enum MenuImgs { ARCHER_WORD, BARBARO_WORD, MAGE_WORD, ROGUE_WORD, TROLL_WORD, URUKHAY_WORD, BACKGROUND, BACK_AFTER, BACK_BEFORE, BACK_OK };
public:
    MainMenu();
    static void drawMainMenu(int x, int y, QPainter *painter);
    static bool moveCursor(Direction dir);
    static PlayerClass whoIsSelected();
    static void delayCont();
    static bool isDelay();
};

#endif // MAINMENU_H
