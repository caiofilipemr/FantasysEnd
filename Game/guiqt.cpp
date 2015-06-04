#include "guiqt.h"

const int GUIQT::size_x = 11;
const int GUIQT::size_y = 15;
const int GUIQT::range_i = 5;
const int GUIQT::range_j = 7;
const int GUIQT::pix_per_tile = 32;

GUIQT::GUIQT()
{
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

    Direction player_direction = draw_player->getEyeDirection();

    QPixmap *tile = new QPixmap(QString::fromStdString(draw_map->getImgWay()));
    QPixmap player_image(QString::fromStdString(draw_player->getImgWay()));
    player_image = player_image.copy((3 + (cont_frames / 5) % 3) * 16, int(player_direction) * 16, 16, 16);

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

    switch (int(player_direction)) {
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

    //Desenha todas as camadas
    for (i = begin_i, index_i = -1; index_i < size_x + 1; index_i++, i++) {
        for (j = begin_j, index_j = -1; index_j < size_y + 1; index_j++, j++) {
            if (m_base[i][j]) painter->drawPixmap(index_j * ppt + column, index_i * ppt + row, ppt, ppt, tile->copy(((m_base[i][j]-1) % 57) * 17, (m_base[i][j] / 57) * 17, 16, 16));
            if (m_s_base[i][j]) painter->drawPixmap(index_j * ppt + column, index_i * ppt + row, ppt, ppt, tile->copy(((m_s_base[i][j]-1) % 57) * 17, (m_s_base[i][j] / 57) * 17, 16, 16));
            if (m_obj[i][j]) painter->drawPixmap(index_j * ppt + column , index_i * ppt + row, ppt, ppt, tile->copy(((m_obj[i][j]-1) % 57) * 17, (m_obj[i][j] / 57) * 17, 16, 16));
            if (m_col[i][j] == 2) painter->drawPixmap(index_j * ppt + column , index_i * ppt + row, ppt, ppt, tile->copy(26 * 17, 8 * 17, 16, 16));
            //Descomentar as duas proximas linhas caso queira usar a opção com melhor desempenho!!!
            //if (m_iso[i][j]) painter->drawPixmap(index_j * ppt + column, index_i * ppt + row, ppt, ppt, tile->copy(((m_iso[i][j]-1) % 57) * 17, (m_iso[i][j] / 57) * 17, 16, 16));
            //if (m_s_iso[i][j]) painter->drawPixmap(index_j * ppt + column, index_i * ppt + row, ppt, ppt, tile->copy(((m_s_iso[i][j]-1) % 57) * 17, (m_s_iso[i][j] / 57) * 17, 16, 16));
        }
    }

    //Desenha a metade de baixo do jogador
    painter->drawPixmap((range_j + dif_j) * ppt, (range_i + dif_i) * ppt, ppt, 16, player_image.copy(0,8,16,8));

//    OPÇÃO DE DESENHO DA SUPER ISOMETRICA COM MENOS CÓDIGO E PIOR DESEMPENHO!!!
    for (i = begin_i, index_i = -1; index_i < size_x + 1; index_i++, i++) {
        for (j = begin_j, index_j = -1; index_j < size_y + 1; index_j++, j++)
            if (m_iso[i][j]) painter->drawPixmap(index_j * ppt + column, index_i * ppt + row, ppt, ppt, tile->copy(((m_iso[i][j]-1) % 57) * 17, (m_iso[i][j] / 57) * 17, 16, 16));
    }

//    OPÇÃO DE DESENHO DA ISOMETRICA COM MAIS CÓDIGO E MELHOR DESEMPENHO!!!
//    //Redesenha a camada isometrica de onde o jogador está indo
//    if (m_iso[player_cordenates.i][player_cordenates.j])
//        painter->drawPixmap((range.j) * ppt + column, range.i * ppt + row, ppt, ppt, tile->copy(((m_iso[player_cordenates.i][player_cordenates.j]-1) % 57) * 17, (m_iso[player_cordenates.i][player_cordenates.j] / 57) * 17, 16, 16));
//    //Redesenha a camada isometrica de onde o jogador saiu
//    if (m_iso[(player_cordenates - aux).i][(player_cordenates - aux).j])
//        painter->drawPixmap((range_j) * ppt + column, range_i * ppt + row, ppt, ppt, tile->copy(((m_iso[(player_cordenates - aux).i][(player_cordenates - aux).j]-1) % 57) * 17, (m_iso[(player_cordenates - aux).i][(player_cordenates - aux).j] / 57) * 17, 16, 16));

    //Desenha a metade de cima do jogador
    painter->drawPixmap(((range_j) + dif_j) * ppt, (((range_i) + dif_i) - 1) * ppt + 16, ppt, 16, player_image.copy(0,0,16,8));//cabeça

//    OPÇÃO DE DESENHO DA SUPER ISOMETRICA COM MENOS CÓDIGO E PIOR DESEMPENHO!!!
    for (i = begin_i, index_i = -1; index_i < size_x + 1; index_i++, i++) {
        for (j = begin_j, index_j = -1; index_j < size_y + 1; index_j++, j++)
            if (m_s_iso[i][j]) painter->drawPixmap(index_j * ppt + column, index_i * ppt + row, ppt, ppt, tile->copy(((m_s_iso[i][j]-1) % 57) * 17, (m_s_iso[i][j] / 57) * 17, 16, 16));
    }

//    OPÇÃO DE DESENHO DA SUPER ISOMETRICA COM MAIS CÓDIGO E MELHOR DESEMPENHO!!!
//    //Redesenha a camada super isometrica de onde a metade de baixo do jogador esta indo
//    if (m_s_iso[player_cordenates.i][player_cordenates.j])
//        painter->drawPixmap((range.j) * ppt + column, range.i * ppt + row, ppt, ppt, tile->copy(((m_s_iso[player_cordenates.i][player_cordenates.j]-1) % 57) * 17, (m_s_iso[player_cordenates.i][player_cordenates.j] / 57) * 17, 16, 16));
//    //Redesenha a camada super isometrica de onde a metade de baixo do jogador saiu
//    if (m_s_iso[(player_cordenates - aux).i][(player_cordenates - aux).j])
//        painter->drawPixmap((range_j) * ppt + column, range_i * ppt + row, ppt, ppt, tile->copy(((m_s_iso[(player_cordenates - aux).i][(player_cordenates - aux).j]-1) % 57) * 17, (m_s_iso[(player_cordenates - aux).i][(player_cordenates - aux).j] / 57) * 17, 16, 16));
//    //Redesenha a camada super isometrica de onde a metade de cima do jogador esta indo
//    if (m_s_iso[player_cordenates.i-1][player_cordenates.j])
//        painter->drawPixmap((range.j) * ppt + column, (range.i-1) * ppt + row, ppt, ppt, tile->copy(((m_s_iso[player_cordenates.i-1][player_cordenates.j]-1) % 57) * 17, (m_s_iso[player_cordenates.i-1][player_cordenates.j] / 57) * 17, 16, 16));
//    //Redesenha a camada super isometrica de onde a metade de cima do jogador saiu
//    if (m_s_iso[(player_cordenates - aux).i-1][(player_cordenates - aux).j])
//        painter->drawPixmap((range_j) * ppt + column, (range_i-1) * ppt + row, ppt, ppt, tile->copy(((m_s_iso[(player_cordenates - aux).i-1][(player_cordenates - aux).j]-1) % 57) * 17, (m_s_iso[(player_cordenates - aux).i-1][(player_cordenates - aux).j] / 57) * 17, 16, 16));
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
