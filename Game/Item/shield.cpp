#include "shield.h"

const int Shield::guard_shield = 1; //Multiplicador de pontos de SHIELD
const int Shield::shield_weight = 2;

Shield::Shield(std::string new_img_way, int new_item_level = 0) : Item(new_item_level, shield_weight, new_img_way)
{
    guard = item_level * guard_shield;
}

Shield::~Shield()
{

}

int Shield::getGuard()
{
    return guard;
}

