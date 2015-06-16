#include "rod.h"

const int Rod::rod_damage = 7;
const int Rod::rod_guard = 2;
const int Rod::rod_weight = 1;
std::string Rod::rod_img_way = "Inventory/Items/rod.png";

Rod::Rod(int new_item_level = 0) : Weapon(new_item_level, rod_damage, rod_guard, rod_weight, rod_img_way)
{

}

Rod::~Rod()
{

}

void Rod::setImgWay(std::string new_img_way)
{
    rod_img_way = new_img_way;
}

