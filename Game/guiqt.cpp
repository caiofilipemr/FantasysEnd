#include "guiqt.h"
#include "Interface/StatusBar/statusbar.h"

const int GUIQT::size_x = 11;
const int GUIQT::size_y = 15;
const int GUIQT::range_i = 5;
const int GUIQT::range_j = 7;
const int GUIQT::pix_per_tile = 32;
const int GUIQT::n_battle_options = 4;
const int GUIQT::battle_delay = 5;
const int GUIQT::text_position[2] = {2 * 32, 6 * 32};
const int GUIQT::width_options[4] = {245, 271, 297, 323};

//Attack - x = 5 , y = 248.
//	Magic - x = 5, y = 274.
//	Items - x = 5, y = 300.
//	Run - x = 5, y = 326.

GUIQT::GUIQT() : bg_battle(QString::fromStdString(Battle::background_img_way)), cursor_battle(QString::fromStdString(Battle::cursor_img_way)),
                 bg_black("Battle/img_preta.png"), inventory(NULL)
{
    selected_option = 0;
    battle_delay_cont = 0;
    mensage_type = BUFFER;
}

void GUIQT::setMoveMapDirection(Direction dir, int &column, int &row, int &cont_frames, int &limit)
{
    column = row = 0;
    switch (int(dir)) {
    case LEFT:
        column = cont_frames * limit;
        break;

    case UP:
        row = cont_frames * limit;
        break;

    case RIGHT:
        column = cont_frames * -limit;
        break;

    case DOWN:
        row = cont_frames * -limit;
        break;
    }
}

void GUIQT::drawHUD()
{
    Bar hp_bar(150, 18, draw_player->getHPMax(), "red");
    Bar mp_bar(150, 18, draw_player->getMPMax(), "blue");
    painter->drawPixmap(8, 8, 21, 20, QPixmap("Battle/hp.png")); //Escreve "HP"
    hp_bar.setSizeBar(draw_player->getHP());
    hp_bar.draw(painter, 35, 9); //Desenha a barra de HP
    painter->drawPixmap(210, 8, 24, 20, QPixmap("Battle/mp.png")); //Escreve "MP"
    mp_bar.setSizeBar(draw_player->getMP());
    mp_bar.draw(painter, 240, 9); //Desenha a barra de MP
    Write::writeHPorMP(QString::number(draw_player->getHP()), QString::number(draw_player->getHPMax()), 35, 9, hp_bar.getTotalW(), 18, painter);
    Write::writeHPorMP(QString::number(draw_player->getMP()), QString::number(draw_player->getMPMax()), 240, 9, mp_bar.getTotalW(), 18, painter);
    Write::writeText("LVL " + QString::number(draw_player->getLevel()), 410, 0, 70, 36, painter);
}

GUIQT::~GUIQT()
{
    delete inventory;
}

void GUIQT::drawMap()
{
    int begin_i, begin_j, index_i, index_j, i, j, ppt = pix_per_tile;
    int dif_i = 0, dif_j = 0;

    Cordenates back_player_cordenates = draw_player->getBackCordenates();
    int pos_i =(back_player_cordenates).i;
    int pos_j = (back_player_cordenates).j;
    int cont_frames = draw_player->getCont();
    int row = 0, column = 0, limit = ppt / Character::getLimit();
    int **m_base = draw_map->getBase(),
        **m_s_base = draw_map->getSuperBase(),
        **m_obj = draw_map->getObjects(),
        **m_iso = draw_map->getIsometric(),
        **m_s_iso = draw_map->getSuperIsometric();
    Object *** m_itera = draw_map->getMatIteration();

    Direction player_direction = draw_player->getEyeDirection();

    QPixmap *tile = new QPixmap(QString::fromStdString(draw_map->getImgWay()));
    QPixmap player_image(QString::fromStdString(draw_player->getImgWay()));
    player_image = player_image.copy((0 + (cont_frames / (Character::getLimit() / 3) % 3)) * 32, int(player_direction) * 32, 32, 32);
    QPixmap mobs_images[draw_mobs->size()];
    for (i = 0; i < int(draw_mobs->size()); i++) {
        mobs_images[i] = QString::fromStdString((*draw_mobs)[i]->getImgWay());
        mobs_images[i] = mobs_images[i].copy((((*draw_mobs)[i]->getCont() / (Character::getLimit() / 3) % 3)) * 32, int((*draw_mobs)[i]->getEyeDirection()) * 32, 32, 32);
    }

    begin_i = pos_i - (range_i + 1);
    begin_j = pos_j - (range_j + 1);

    setMoveMapDirection(player_direction, column, row, cont_frames, limit);

    //Desenha todas as camadas
    for (i = begin_i, index_i = -1; index_i < size_x + 1; index_i++, i++) {
        for (j = begin_j, index_j = -1; index_j < size_y + 1; index_j++, j++) {
            if (m_base[i][j]) painter->drawPixmap(index_j * ppt + column, index_i * ppt + row, ppt, ppt, tile->copy(((m_base[i][j]-1) % 57) * 17, (m_base[i][j] / 57) * 17, 16, 16));
            if (m_s_base[i][j]) painter->drawPixmap(index_j * ppt + column, index_i * ppt + row, ppt, ppt, tile->copy(((m_s_base[i][j]-1) % 57) * 17, (m_s_base[i][j] / 57) * 17, 16, 16));
            if (m_obj[i][j]) painter->drawPixmap(index_j * ppt + column , index_i * ppt + row, ppt, ppt, tile->copy(((m_obj[i][j]-1) % 57) * 17, (m_obj[i][j] / 57) * 17, 16, 16));
            if (m_itera[i][j] != NULL) painter->drawPixmap(index_j * ppt + column , index_i * ppt + row, ppt, ppt, QPixmap(QString::fromStdString(draw_map->getObjectMap(Cordenates(i,j))->getImgWay())));
        }
    }

    int xb = begin_i - 1, xe = begin_i + size_x + 2, yb = begin_j - 1, ye = begin_j + size_y + 2;
    Cordenates mob_cordenates[draw_mobs->size()];

    int row_monster = 0, column_monster = 0;

    //Desenha a metade de baixo do jogador e mobs
    painter->drawPixmap((range_j + dif_j) * ppt, (range_i + dif_i) * ppt, ppt, 16, player_image.copy(0,16,32,16));
    cont_frames = Monster::getContMonster();
    for (i = 0; i < int(draw_mobs->size()); i++) {
        mob_cordenates[i] = (*draw_mobs)[i]->getCordenates();
        if (hasPoint(mob_cordenates[i].i, mob_cordenates[i].j)) {
            if (Monster::getMonsterIsWalking())
                mob_cordenates[i] = mob_cordenates[i] - (*draw_mobs)[i]->getDirection();
            setMoveMapDirection((*draw_mobs)[i]->getDirection(), column_monster, row_monster, cont_frames, limit);
            painter->drawPixmap((mob_cordenates[i].j - begin_j - 1) * ppt - column_monster + column, (mob_cordenates[i].i - begin_i - 1) * ppt - row_monster + row, ppt, 16, mobs_images[i].copy(0,16,32,16));
        }
    }

//    OPÇÃO DE DESENHO DA ISOMETRICA !!!
    for (i = begin_i, index_i = -1; index_i < size_x + 1; index_i++, i++) {
        for (j = begin_j, index_j = -1; index_j < size_y + 1; index_j++, j++)
            if (m_iso[i][j]) painter->drawPixmap(index_j * ppt + column, index_i * ppt + row, ppt, ppt, tile->copy(((m_iso[i][j]-1) % 57) * 17, (m_iso[i][j] / 57) * 17, 16, 16));
    }

    //Desenha a metade de cima do jogador e mobs
    painter->drawPixmap(((range_j) + dif_j) * ppt, (((range_i) + dif_i) - 1) * ppt + ppt / 2, ppt, 16, player_image.copy(0,0,32,16));//cabeça
    for (i = 0; i < int(draw_mobs->size()); i++) {
        if (hasPoint(mob_cordenates[i].i, mob_cordenates[i].j)) {
            setMoveMapDirection((*draw_mobs)[i]->getDirection(), column_monster, row_monster, cont_frames, limit);
            painter->drawPixmap((mob_cordenates[i].j - begin_j - 1) * ppt - column_monster + column, (mob_cordenates[i].i - begin_i - 2) * ppt + ppt / 2 - row_monster + row, ppt, 16, mobs_images[i].copy(0,0,32,16));
        }
    }

//    OPÇÃO DE DESENHO DA SUPER ISOMETRICA!!!
    for (i = begin_i, index_i = -1; index_i < size_x + 1; index_i++, i++) {
        for (j = begin_j, index_j = -1; index_j < size_y + 1; index_j++, j++)
            if (m_s_iso[i][j]) painter->drawPixmap(index_j * ppt + column, index_i * ppt + row, ppt, ppt, tile->copy(((m_s_iso[i][j]-1) % 57) * 17, (m_s_iso[i][j] / 57) * 17, 16, 16));
    }

    drawHUD();
}

void GUIQT::drawInventory()
{
    inventory->draw();
}

void GUIQT::drawBattle()
{
    painter->drawPixmap(0, 0, size_y * pix_per_tile, size_x * pix_per_tile, bg_battle);
    painter->drawPixmap(1, width_options[selected_option], 22, 21, cursor_battle);
    painter->drawPixmap(5*32, 1.5*32, 320, 192,QPixmap(QString::fromStdString(Battle::getImgWayMonster())));
    QPixmap player_image(QString::fromStdString(draw_player->getImgWay()));
    player_image = player_image.copy(0 * 32, 2* 32, 32, 32);
    painter->drawPixmap(2*32, 6.5*32, 32, 32, player_image);

    switch (mensage_type) {
    case MISS:
         painter->drawPixmap(text_position[int(text_right)], 5 * 32 - battle_delay_cont * 5, 26, 16, QPixmap("Battle/miss.png"));
        break;
    case DODGE:
        painter->drawPixmap(text_position[int(text_right)], 5 * 32 - battle_delay_cont * 5, 38, 16, QPixmap("Battle/dodge.png"));
        break;
    case CRITICAL:
        painter->drawPixmap(text_position[int(text_right)], 5 * 36 - battle_delay_cont * 5, 45, 14, QPixmap("Battle/critical.png"));
        Write::writeText(battle_text, text_position[int(text_right)], 5 * 32 - battle_delay_cont * 5, painter, true);
        break;
    case HIT:
        Write::writeText(battle_text, text_position[int(text_right)], 5 * 32 - battle_delay_cont * 5, painter);
        break;
    default:
        break;
    }

    drawHUD();
}

void GUIQT::drawBrokenStone()
{

}

void GUIQT::drawGameOver()
{
    painter->drawPixmap(0, 0, 15 * 32, 11 * 32, QPixmap("Images/game_over.jpg"));
}

void GUIQT::drawMainMenu()
{
    MainMenu::drawMainMenu(0, 0, painter);
}

void GUIQT::drawPauseScreen()
{
    painter->drawPixmap(0, 0, pix_per_tile * size_y, pix_per_tile * size_x, QPixmap("Inventory/squary_press.png"));
    Write::writeText("PAUSE", 0, 0, 15 * 32, 11 * 32, painter);
}

void GUIQT::drawStatusBar()
{
    StatusBar::draw(painter, draw_player->getStrenght(), draw_player->getAgility(), draw_player->getIntelligence(), draw_player->getDamage(), draw_player->getGuard());
}

void GUIQT::setDrawPlayer(Player *new_draw_player)
{
    this->draw_player = new_draw_player;
    //inventory->setPlayer(draw_player);
    inventory->setPlayer(draw_player);
}

void GUIQT::setDrawMap(Map *new_draw_map)
{
    this->draw_map = new_draw_map;
}

void GUIQT::setDrawMobs(std::vector<Monster *> *new_draw_mobs)
{
    this->draw_mobs = new_draw_mobs;
}

void GUIQT::drawTransictionMapBattle(int px_to_black)
{
    painter->drawPixmap(0, 0, px_to_black, size_x * pix_per_tile, bg_black);
    painter->drawPixmap(size_y * pix_per_tile - px_to_black, 0, px_to_black, size_x * pix_per_tile, bg_black);
}

void GUIQT::drawTutorial()
{
    painter->drawPixmap(0, 0, pix_per_tile * size_y, pix_per_tile * size_x, QPixmap("Inventory/squary_press.png"));
    Write::writeText("MINI TUTORIAL", 0, 0, 15 * 32, 5 * 32, painter);
    Write::writeText("MOVE UP        W", 0, 8, 15 * 32, 6 * 32, painter);
    Write::writeText("MOVE DOWN      S", 0, 16, 15 * 32, 7 * 32, painter);
    Write::writeText("MOVE LEFT       A", 0, 24, 15 * 32, 8 * 32, painter);
    Write::writeText("MOVE RIGHT      D", 0, 32, 15 * 32, 9 * 32, painter);
    Write::writeText("PAUSE           Q", 0, 40, 15 * 32, 10 * 32, painter);
    Write::writeText("OPEN INVENTORY  E", 0, 48, 15 * 32, 11 * 32, painter);
    Write::writeText("ACTION      SPACE", 0, 56, 15 * 32, 12 * 32, painter);
    Write::writeText("PRESS SPACE TO PLAY", 0, 128, 15 * 32, 13 * 32, painter);
}

void GUIQT::setQPainter(QPainter *new_painter)
{
    painter = new_painter;
    if (inventory) delete inventory;
    inventory = new InventoryGUI(400,246,15*32,11*32, draw_player, painter);
}

void GUIQT::setCursor(int x, int y, ButtonCursor button)
{
    inventory->setCursor(x, y, button);
}

bool GUIQT::moveCursorBattle(Direction dir)
{
    bool ret = false;
    switch (dir) {
    case UP:
        selected_option--;
        ret = true;
        break;

    case DOWN:
        selected_option++;
        ret = true;
        break;
    default:
        break;
    }
    if (selected_option == n_battle_options) selected_option = 0;
    else if (selected_option < 0) selected_option = n_battle_options - 1;
    return ret;
}

bool GUIQT::moveCursorMM(Direction dir)
{
    return MainMenu::moveCursor(dir);
}

PlayerClass GUIQT::getSelectedOptionMM()
{
    return MainMenu::whoIsSelected();
}

BattleOptions GUIQT::getSelectedOptionBattle()
{
    return BattleOptions(selected_option);
}

void GUIQT::resetSelectedOption()
{
    selected_option = 0;
}

void GUIQT::battleDelayCont()
{
    battle_delay_cont++;
    if (battle_delay_cont > battle_delay) {
        battle_delay_cont = 0;
        battle_text.clear();
        mensage_type = BUFFER;
    }
}

void GUIQT::MMDelayCont()
{
    MainMenu::delayCont();
}

bool GUIQT::isBattleDelay()
{
    return battle_delay_cont;
}

bool GUIQT::isMMDelay()
{
    return MainMenu::isDelay();
}

void GUIQT::setBattleText(Exceptions type, QString new_battle_text, bool new_text_right)
{
    mensage_type = type;
    text_right = new_text_right;
    battle_text = new_battle_text;
}

void GUIQT::setBattleText(Exceptions type, bool new_text_right)
{
    mensage_type = type;
    text_right = new_text_right;
}

void GUIQT::resetStatusBar()
{
    StatusBar::reset();
}

void GUIQT::clearInventory()
{
    inventory->clear();
}

void GUIQT::setChest(Chest *new_chest)
{
    inventory->setChest(new_chest);
}

int GUIQT::takeItemChest()
{
    return inventory->takeItemChest();
}

int GUIQT::rowItemChest()
{
    return inventory->getRowItem();
}

int GUIQT::rowCommand()
{
    return inventory->getRowCommand();
}

InventorySelection GUIQT::currentInventorySelected()
{
    return inventory->getInventorySelection();
}

void GUIQT::setCommands(vector<string> commands)
{
    inventory->setCommands(commands);
}

bool GUIQT::isRowCommand()
{
    return inventory->isRowCommand();
}

void GUIQT::clearCursor()
{
    inventory->clearCursor();
}
