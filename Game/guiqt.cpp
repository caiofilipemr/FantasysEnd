#include "guiqt.h"

const int GUIQT::size_x = 11;
const int GUIQT::size_y = 15;
const int GUIQT::range_i = 5;
const int GUIQT::range_j = 7;
const int GUIQT::pix_per_tile = 32;
const int GUIQT::n_battle_options = 2;
const int GUIQT::battle_delay = 5;
const int GUIQT::text_position[2] = {2 * 32, 6 * 32};

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

GUIQT::GUIQT() : bg_battle(QString::fromStdString(Battle::background_img_way)), cursor_battle(QString::fromStdString(Battle::cursor_img_way)), width_options(new int[n_battle_options])
{
    inventory = new InventInterface(400,246,15*32,11*32);
    width_options[ATTACK] = 0;
    width_options[ITEM] = 3 * 32 - 10;
    selected_option = 0;
    battle_delay_cont = 0;
    battle_text_color = Qt::white;
}

GUIQT::~GUIQT()
{
    delete inventory;
    delete width_options;
}

void GUIQT::drawMap()
{
    int begin_i, begin_j, index_i, index_j, i, j, ppt = pix_per_tile;
    int dif_i = 0, dif_j = 0;
//    Direction aux = SLEEP;
//    if (draw_player->getIsWalking()) {
//        aux = draw_player->getEyeDirection();
//    }
    //Cordenates player_cordenates = draw_player->getCordenates();
    Cordenates back_player_cordenates = draw_player->getBackCordenates();
    //Cordenates range(range_i, range_j);
    //range = range + aux;
    int pos_i =(back_player_cordenates).i;
    int pos_j = (back_player_cordenates).j;
    int cont_frames = draw_player->getCont();
    int row = 0, column = 0, limit = ppt / Character::getLimit();
    int **m_base = draw_map->getBase(),
        **m_s_base = draw_map->getSuperBase(),
        **m_obj = draw_map->getObjects(),
        **m_iso = draw_map->getIsometric(),
        **m_s_iso = draw_map->getSuperIsometric(),
        **m_col = draw_map->getColision();
    Object *** m_itera = draw_map->getMatIteration();

    Direction player_direction = draw_player->getEyeDirection();

    QPixmap *tile = new QPixmap(QString::fromStdString(draw_map->getImgWay()));
    QPixmap player_image(QString::fromStdString(draw_player->getImgWay()));
    player_image = player_image.copy((3 + (cont_frames / (Character::getLimit() / 3) % 3)) * 16, int(player_direction) * 16, 16, 16);
    QPixmap mobs_images[draw_mobs->size()];
    for (i = 0; i < int(draw_mobs->size()); i++) {
        mobs_images[i] = QString::fromStdString((*draw_mobs)[i]->getImgWay());
        mobs_images[i] = mobs_images[i].copy((0 + ((*draw_mobs)[i]->getCont() / (Character::getLimit() / 3) % 3)) * 32, int((*draw_mobs)[i]->getEyeDirection()) * 32 + 128, 32, 32);
    }

//    VERIFICAÇÃO DAS BORDAS. POR ENQUANTO NÃO USAREMOS
//    if (pos_i - range_i <= 0) {//Verifica se não vai mostrar mapa inexistente (I NEGATIVO)
//        begin_i = 0;
//        dif_i = pos_i - range_i;
//        //mov_map = false;
//    }
//    else if (pos_i + range_i > size_i) { //Verifica se não vai mostrar mapa inexistente (I MAIOR QUE O MAPA)
//        begin_i = size_i - (2 * range_i + 1);
//        dif_i = pos_i + range_i - size_i;
//        //mov_map = false;
//    } else begin_i = pos_i - (range_i + 1); //VERIFICAR O PORQUÊ DO + 1

//    if (pos_j - range_j <= 0) { //Idem com o J (J NEGATIVO)
//        begin_j = 0;
//        dif_j = pos_j - range_j;
//        //mov_map = false;
//    }
//    else if (pos_j + range_j >= size_j) { //Idem com o J (J MAIOR QUE O MAPA)
//        begin_j = size_j - 2 * range_j;
//        dif_j = pos_j + range_j - size_j;
//        //mov_map = false;
//    } else begin_j = pos_j - (range_j + 1); //VERIFICAR O PORQUÊ DO + 1

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
    painter->drawPixmap((range_j + dif_j) * ppt, (range_i + dif_i) * ppt, ppt, 16, player_image.copy(0,8,16,8));
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
    painter->drawPixmap(((range_j) + dif_j) * ppt, (((range_i) + dif_i) - 1) * ppt + ppt / 2, ppt, 16, player_image.copy(0,0,16,8));//cabeça
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
}

void GUIQT::drawInventory()
{
  inventory->draw(painter);
}

void GUIQT::drawBattle()
{
    painter->drawPixmap(0, 0, size_y * pix_per_tile, size_x * pix_per_tile, bg_battle);
    painter->drawPixmap(width_options[selected_option], 10*32 + 2,16,16,cursor_battle);
    painter->drawPixmap(5*32, 2*32, 320, 192,QPixmap(QString::fromStdString(Battle::getImgWayMonster())));
    QPixmap player_image(QString::fromStdString(draw_player->getImgWay()));
    player_image = player_image.copy(3 * 16, 2* 16, 16, 16);
    painter->drawPixmap(2*32, 7*32, 32, 32, player_image);
    painter->setFont(QFont("Times", 16, QFont::Bold));
    painter->setPen(QPen(battle_text_color));
    painter->drawText(text_position[int(text_right)], 5 * 32 - battle_delay_cont * 5, 200, 30, Qt::AlignVCenter, battle_text);
}

void GUIQT::drawBrokenStone()
{

}

void GUIQT::drawGameOver()
{
    painter->drawPixmap(0, 0, 15 * 32, 11 * 32, QPixmap("Images/game_over.jpg"));
}

void GUIQT::setDrawPlayer(Player *new_draw_player)
{
    this->draw_player = new_draw_player;
}

void GUIQT::setDrawMap(Map *new_draw_map)
{
    this->draw_map = new_draw_map;
}

void GUIQT::setDrawMobs(std::vector<Monster *> *new_draw_mobs)
{
    this->draw_mobs = new_draw_mobs;
}

void GUIQT::setQPainter(QPainter *new_painter)
{
    painter = new_painter;
}

void GUIQT::setCursor(int x, int y)
{
    this->inventory->setCursor(x, y);
}

int GUIQT::getIndexItemInventory()
{
    return inventory->getNumberItemInv();
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

BattleOptions GUIQT::getSelectedOption()
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
    }
}

bool GUIQT::isBattleDelay()
{
    return battle_delay_cont;
}

void GUIQT::setBattleText(QString new_battle_text, QColor color, bool new_text_right)
{
    battle_text = new_battle_text;
    battle_text_color = color;
    text_right = new_text_right;
}

void GUIQT::rightButton()
{
    inventory->isMessage();
}

void GUIQT::leftButton()
{
    inventory->notMessage();
}
