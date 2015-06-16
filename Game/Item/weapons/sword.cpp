#include "sword.h"

const int Sword::sword_damage = 12;
const int Sword::sword_guard = 3;
const int Sword::sword_weight = 5;
std::string Sword::sword_img_way = "Inventory/Items/sword.png";

Sword::Sword(int new_item_level = 0) : Weapon(new_item_level, sword_damage, sword_guard, sword_weight, sword_img_way)
{

}

Sword::~Sword()
{

}

void Sword::setImgWay(std::string new_img_way)
{
    sword_img_way = new_img_way;
}

