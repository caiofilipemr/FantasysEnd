#include "mainmenu.h"
#include "Character/Player/Raca/Elf/archer.h"
#include "Character/Player/Raca/Elf/mage.h"
#include "Character/Player/Raca/Orc/troll.h"
#include "Character/Player/Raca/Orc/urukhay.h"
#include "Character/Player/Raca/Human/barbaro.h"
#include "Character/Player/Raca/Human/rogue.h"

const char * MainMenu::img_way[10] = {"Menu/archer.png", "Menu/barbaro.png",
                                      "Menu/mage.png", "Menu/rogue.png",
                                      "Menu/troll.png", "Menu/urukhay.png",
                                      "Menu/back.png", "Menu/back_after.png",
                                      "Menu/back_before.png", "Menu/back_ok.png",
                                    };
int MainMenu::width = 480;
int MainMenu::height = 352;
int MainMenu::selected_option = 0;
int MainMenu::n_class_options = 6;
int MainMenu::delay_cont = 0;
int MainMenu::max_delay = 16;
int MainMenu::back_selected = -1;

//void GUIQT::battleDelayCont()
//{
//    battle_delay_cont++;
//    if (battle_delay_cont > battle_delay) {
//        battle_delay_cont = 0;
//        battle_text.clear();
//        mensage_type = BUFFER;
//    }
//}

int MainMenu::att_ini_class[6][3] = { Archer::arc_agility, Archer::arc_strenght, Archer::arc_intelligence,
                                      Barbaro::barb_agility, Barbaro::barb_strenght, Barbaro::barb_intelligence,
                                      Mage::mage_agility, Mage::mage_strenght, Mage::mage_intelligence,
                                      Rogue::rog_agility, Rogue::rog_strenght, Rogue::rog_intelligence,
                                      Troll::troll_agility, Troll::troll_strenght, Troll::troll_intelligence,
                                      Urukhay::hay_agility, Urukhay::hay_strenght, Urukhay::hay_intelligence,
                                    };

int MainMenu::getBackSelectedRow()
{
    int row = selected_option + back_selected;
    if (row >= 0 && row < n_class_options) return row;
    if (row == n_class_options) return 0;
    return n_class_options - 1;
}

MainMenu::MainMenu()
{
}

void MainMenu::drawMainMenu(int x, int y, QPainter *painter)
{
    painter->drawPixmap(x, y, width, height, QPixmap(img_way[BACKGROUND]));
    QPixmap name(img_way[selected_option]);
    int central = width/2 - name.width()/2, w = (width - central) / max_delay, bw = width, wb = w * delay_cont * (back_selected);
    if (isDelay()) {
        if (back_selected > 0) painter->drawPixmap(20, 285, 24, 47, QPixmap(img_way[BACK_BEFORE]));
        else painter->drawPixmap(436, 285, 24, 47, QPixmap(img_way[BACK_AFTER]));

//Before: x = 20, y = 285, w = 24, h = 47
//After: x = 436, y = 285, w = 24, h = 47

        QPixmap back_name(img_way[getBackSelectedRow()]);
        if (back_selected > 0) {
            bw = 0;
            wb = ((width - (width - central) + name.width()) / max_delay) * delay_cont * (back_selected) - name.width();
        }
        painter->drawPixmap(bw + wb, 12, name.width(), name.height(), name);
        painter->drawPixmap((width/2 - back_name.width()/2) + w * delay_cont * (back_selected), 12, back_name.width(), back_name.height(), back_name);
    }
    else painter->drawPixmap(central, 12, name.width(), name.height(), name);
    Bar agi(125, 16, 20, "green"), str(125, 16, 20, "red"), itl(125, 16, 20, "blue");
    agi.setSizeBar(att_ini_class[selected_option][AGILITY]);
    str.setSizeBar(att_ini_class[selected_option][STRENGHT]);
    itl.setSizeBar(att_ini_class[selected_option][INTELLIGENCE]);
    agi.draw(painter, 310, 93); //Desenha barra de agility
    str.draw(painter, 310, 156); //Desenha barra de strenght
    itl.draw(painter, 310, 219); //Desenha barra de intelligence
}

//  Hability: x = 310, y = 93, w = 150, h = 16
//	Strength: x = 310, y = 166, w = 150, h = 16
//	Intelligence: x = 310, y = 219, w = 150, h = 16

bool MainMenu::moveCursor(Direction dir)
{
    if (isDelay()) return false;
    switch (dir) {
    case RIGHT:
        selected_option++;
        back_selected = -1;
        break;

    case LEFT:
        selected_option--;
        back_selected = 1;
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

void MainMenu::delayCont()
{
    delay_cont++;
    if (delay_cont > max_delay) {
        delay_cont = back_selected = 0;
    }
}

bool MainMenu::isDelay()
{
    return delay_cont;
}
