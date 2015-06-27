#include "mace.h"

const int Mace::mace_damage = 13;
const int Mace::mace_guard = 3;
const int Mace::mace_weight = 8;
std::string Mace::mace_img_way = "Inventory/Items/mace.png";

Mace::Mace(int new_item_level = 0) : Weapon(new_item_level, mace_damage, mace_guard, mace_weight, mace_img_way, "MACE")
{
}

Mace::~Mace()
{

}

void Mace::setImgWay(std::string new_img_way)
{
    mace_img_way = new_img_way;
}

