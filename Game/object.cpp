#include "object.h"

Object::Object(int new_pos_i, int new_pos_j, std::string new_img_way = "") : pos_i(new_pos_i), pos_j(new_pos_j), img_way(new_img_way)
{
}

Object::~Object()
{

}

Cordenates Object::getCordenates()
{
    return Cordenates(pos_i, pos_j);
}

std::string Object::getImgWay()
{
    return img_way;
}
