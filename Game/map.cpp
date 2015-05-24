#include "map.h"

Map::Map(string new_arch_map, string new_img_way)
{
    ifstream arch_map;

    img_way = new_img_way;

    int i, j;
    char buffercleaner;

    arch_map.open(new_arch_map.c_str());
    arch_map >> size_i >> size_j;

    arch_map >> buffercleaner;
    m_base = new int*[size_i];
    for (i = 0; i < size_i; i++){
        *m_base = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_col[i][j];
        }
    }
    arch_map >> buffercleaner;
    m_s_base = new int*[size_i];
    for (i = 0; i < size_i; i++){
        *m_s_base = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_s_base[i][j];
        }
    }
    arch_map >> buffercleaner;
    m_obj = new int*[size_i];
    for (i = 0; i < size_i; i++){
        *m_obj = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_obj[i][j];
        }
    }
    arch_map >> buffercleaner;
    m_iso = new int*[size_i];
    for (i = 0; i < size_i; i++){
        *m_iso = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_iso[i][j];
        }
    }
    arch_map >> buffercleaner;
    m_col = new int*[size_i];
    for (i = 0; i < size_i; i++){
        *m_col = new int[size_j];
        for (j = 0; j < size_j; j++) {
            arch_map >> m_col[i][j];
        }
    }
    arch_map >> buffercleaner;
    arch_map.close();
}

Map::~Map()
{

}
