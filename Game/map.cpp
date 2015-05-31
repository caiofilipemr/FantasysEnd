#include "map.h"

Map::Map(string new_arch_map, string new_img_way)
{
    can_go = new bool[4];

    ifstream arch_map;

    img_way = new_img_way;

    int i, j;
    char buffercleaner;

    arch_map.open(new_arch_map.c_str());
    arch_map >> size_i >> size_j;

    arch_map >> buffercleaner;
    m_col = new int*[size_i];
    for (i = 0; i < size_i; i++){
        m_col[i] = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_col[i][j];
        }
    }
    arch_map >> buffercleaner;
    m_base = new int*[size_i];
    for (i = 0; i < size_i; i++){
        m_base[i] = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_base[i][j];
        }
    }
    arch_map >> buffercleaner;
    m_s_base = new int*[size_i];
    for (i = 0; i < size_i; i++){
        m_s_base[i] = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_s_base[i][j];
        }
    }
    arch_map >> buffercleaner;
    m_obj = new int*[size_i];
    for (i = 0; i < size_i; i++){
        m_obj[i] = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_obj[i][j];
        }
    }
    arch_map >> buffercleaner;
    m_iso = new int*[size_i];
    for (i = 0; i < size_i; i++){
        m_iso[i] = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_iso[i][j];
        }
    }
    arch_map >> buffercleaner;
    m_s_iso = new int*[size_i];
    for (i = 0; i < size_i; i++){
        m_s_iso[i] = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_s_iso[i][j];
        }
    }
    arch_map >> buffercleaner;
    arch_map.close();

//    for (i = 0; i < size_i; i++){
//        for (j = 0; j < size_j; j++) {
//            cerr << m_col[i][j] << " ";
//        }
//        cerr << endl;
//    }
}

Map::~Map()
{

}

int **Map::getColision()
{
    return m_col;
}

Cordenates Map::getCordenates()
{
    return Cordenates(size_i, size_j);
}

bool Map::hasColision(Cordenates cord)
{
    return bool(m_col[cord.i][cord.j]);
}

bool *Map::getCanGo(Cordenates cord)
{
    can_go[UP] = can_go[DOWN] = can_go[RIGHT] = can_go[LEFT] = true;
    if (m_col[(cord + UP).i][(cord + UP).j]) can_go[UP] = false;
    if (m_col[(cord + DOWN).i][(cord + DOWN).j]) can_go[DOWN] = false;
    if (m_col[(cord + RIGHT).i][(cord + RIGHT).j]) can_go[RIGHT] = false;
    if (m_col[(cord + LEFT).i][(cord + LEFT).j]) can_go[LEFT] = false;
    return can_go;
}

void Map::updateColision(Character *update_character)
{
    Cordenates temp_cord = update_character->getCordenates();
    Direction temp_dir = update_character->getDirection();
    m_col[(temp_cord - temp_dir).i][(temp_cord - temp_dir).j] = 0;
    m_col[temp_cord.i][temp_cord.j] = 2;

    for (int i = 0; i < size_i; i++){
        for (int j = 0; j < size_j; j++) {
            cerr << m_col[i][j] << " ";
        }
        cerr << endl;
    }
}
