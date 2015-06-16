#include "bow.h"

const int Bow::bow_damage = 13;
const int Bow::bow_guard = 1;
const int Bow::bow_weight = 1;
std::string Bow::bow_img_way = "Inventory/Items/bow.png";

Bow::Bow(int new_item_level = 0) : Weapon(new_item_level, bow_damage, bow_guard, bow_weight, bow_img_way)
{

}

Bow::~Bow()
{

}

void Bow::setImgWay(std::string new_img_way)
{
    bow_img_way = new_img_way;
}

