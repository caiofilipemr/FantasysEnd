#include "object.h"

Object::Object(int new_pos_i, int new_pos_j, std::string new_img_way) : pos_i(new_pos_i), pos_j(new_pos_j), img_way(new_img_way)
{
}

int Object::getPosI()
{
    return pos_i;
}

int Object::getPosJ()
{
    return pos_j;
}
