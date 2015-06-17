#include "mainmenu.h"

const char * MainMenu::img_way[10] = {"Menu/back.png", "Menu/archer.png",
                                     "Menu/barbaro.png", "Menu/mage.png",
                                     "Menu/rogue.png", "Menu/troll.png",
                                     "Menu/urukhay.png", "Menu/back_after.png",
                                     "Menu/back_before.png", "Menu/back_ok.png",
                                    };
int MainMenu::width = 480;
int MainMenu::height = 352;
int MainMenu::selected_option = 0;
int MainMenu::selected_option = 6;

MainMenu::MainMenu()
{
}

void MainMenu::drawMainMenu(int x, int y, QPainter *painter)
{
    painter->drawPixmap(x, y, width, height, QPixmap(img_way[BACKGROUND]));
    QPixmap name(img_way[selected_option])
}

bool MainMenu::moveCursor(Direction dir)
{
    switch (dir) {
    case RIGHT:
        selected_option++;
        break;

    case LEFT:
        selected_option--;
        break;
    default:
        return false;
    }
    LOOP_OPTION(selected_option, n_class_options);
    return true;
}

PlayerClass MainMenu::whoIsSelected()
{
    return PlayerClass(selected_option);
}
