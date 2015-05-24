#include "axe.h"

const int Axe::axe_damage = 15;
const int Axe::axe_guard = 4;
const int Axe::axe_weight = 7;
std::string Axe::axe_img_way = "";

Axe::Axe(int new_item_level = 0) : Weapon(new_item_level, axe_damage, axe_guard, axe_weight, axe_img_way)
{

}

Axe::~Axe()
{

}

void Axe::setImgWay(std::string new_img_way)
{
    axe_img_way = new_img_way;
}

