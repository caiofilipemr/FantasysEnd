#include "guiqt.h"

const int GUIQT::size_x = 11;
const int GUIQT::size_y = 15;
const int GUIQT::range_i = 5;
const int GUIQT::range_j = 7;

GUIQT::GUIQT()
{
}

void GUIQT::drawMap()
{
    int begin_i, begin_j, index_i, index_j, i, j;
    int dif_i = 0, dif_j = 0;
    Direction aux = SLEEP;
    if (draw_player->getIsWalking()) {
        aux = draw_player->getEyeDirection();
    }
    int pos_i =(draw_player->getCordenates() - aux).i;
    int pos_j = (draw_player->getCordenates() - aux).j;
    int size_i = draw_map->getCordenates().i, size_j = draw_map->getCordenates().j;
    int cont_frames = draw_player->getCont();
    int row = 0, column = 0;
    int **m_base = draw_map->getBase(),
        **m_s_base = draw_map->getSuperBase(),
        **m_obj = draw_map->getObjects(),
        **m_iso = draw_map->getIsometric(),
        **m_col = draw_map->getColision();
    bool mov_map = true;
    Direction player_direction = draw_player->getEyeDirection();

    QPixmap *tile = new QPixmap(QString::fromStdString(draw_map->getImgWay()));
    QPixmap player_image(QString::fromStdString(draw_player->getImgWay()));
    player_image = player_image.copy((3 + (cont_frames / 5) % 3) * 16, int(player_direction) * 16, 16, 16);

    if (pos_i - range_i <= 0) {//Verifica se não vai mostrar mapa inexistente (I NEGATIVO)
        begin_i = 0;
        dif_i = pos_i - range_i;
        //mov_map = false;
    }
    else if (pos_i + range_i > size_i) { //Verifica se não vai mostrar mapa inexistente (I MAIOR QUE O MAPA)
        begin_i = size_i - (2 * range_i + 1);
        dif_i = pos_i + range_i - size_i;
        //mov_map = false;
    } else begin_i = pos_i - (range_i + 1); //VERIFICAR O PORQUÊ DO + 1
    if (pos_j - range_j <= 0) { //Idem com o J (J NEGATIVO)
        begin_j = 0;
        dif_j = pos_j - range_j;
        //mov_map = false;
    }
    else if (pos_j + range_j >= size_j) { //Idem com o J (J MAIOR QUE O MAPA)
        begin_j = size_j - 2 * range_j;
        dif_j = pos_j + range_j - size_j;
        //mov_map = false;
    } else begin_j = pos_j - (range_j + 1); //VERIFICAR O PORQUÊ DO + 1

    if (mov_map) {
        switch (int(player_direction)) {
        case LEFT:
            column = cont_frames / 1 * 2;
            break;

        case UP:
            row = cont_frames / 1 * 2;
            break;

        case RIGHT:
            column = cont_frames / 1 * -2;
            break;

        case DOWN:
            row = cont_frames / 1 * -2;
            break;
        }
    }

    for (i = begin_i, index_i = -1; index_i < size_x + 1; index_i++, i++) {
        for (j = begin_j, index_j = -1; index_j < size_y + 1; index_j++, j++) {
            if (m_base[i][j]) painter->drawPixmap(index_j * 32 + column, index_i * 32 + row, 32, 32, tile->copy(((m_base[i][j]-1) % 57) * 17, (m_base[i][j] / 57) * 17, 16, 16));
            if (m_s_base[i][j]) painter->drawPixmap(index_j * 32 + column, index_i * 32 + row, 32, 32, tile->copy(((m_s_base[i][j]-1) % 57) * 17, (m_s_base[i][j] / 57) * 17, 16, 16));
            if (m_obj[i][j]) painter->drawPixmap(index_j * 32 + column , index_i * 32 + row, 32, 32, tile->copy(((m_obj[i][j]-1) % 57) * 17, (m_obj[i][j] / 57) * 17, 16, 16));
            if (m_col[i][j] == 2) painter->drawPixmap(index_j * 32 + column , index_i * 32 + row, 32, 32, tile->copy(26 * 17, 8 * 17, 16, 16));
            painter->drawPixmap((range_j + dif_j) * 32, (range_i + dif_i) * 32, 32, 16, player_image.copy(0,8,16,8));
            if (m_iso[i][j]) painter->drawPixmap(index_j * 32 + column, index_i * 32 + row, 32, 32, tile->copy(((m_iso[i][j]-1) % 57) * 17, (m_iso[i][j] / 57) * 17, 16, 16));
        }
    }
    /*if (draw_player->getIsWalking() || player_direction == SLEEP)*/ painter->drawPixmap(((range_j) + dif_j) * 32, (((range_i) + dif_i) - 1) * 32 + 16, 32, 16, player_image.copy(0,0,16,8));//cabeça
}

void GUIQT::drawInventory()
{

}

void GUIQT::drawBattle()
{

}

void GUIQT::drawBrokenStone()
{

}

void GUIQT::setDrawPlayer(Player *new_draw_player)
{
    this->draw_player = new_draw_player;
}

void GUIQT::setDrawMap(Map *new_draw_map)
{
    this->draw_map = new_draw_map;
}

void GUIQT::setQPainter(QPainter *new_painter)
{
    painter = new_painter;
}
