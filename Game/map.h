#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include "globalfunctions.h"
using namespace std;

class Map
{
private:
    string img_way;
    int size_i, size_j;
    int **m_base, **m_s_base, **m_obj, **m_iso, **m_col;
public:
    Map(string new_arch_map, string new_img_way);
    ~Map();
    int ** getColision();
    Cordenates getCordenates();
};

#endif // MAP0_H
