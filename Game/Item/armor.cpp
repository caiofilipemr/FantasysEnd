#include "armor.h"

const int Armor::guard_armor = 2; //Multiplicador de pontos de GUARD
const int Armor::armor_weight = 3;

Armor::Armor(std::string new_img_way, int new_item_level = 0) : Item(new_item_level, armor_weight, new_img_way)
{
    guard = item_level * guard_armor;
}

Armor::~Armor()
{

}

int Armor::getGuard()
{
    return guard;
}

