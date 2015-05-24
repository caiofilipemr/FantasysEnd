#include "potion.h"

const int Potion::potion_weight = 1;

Potion::Potion(std::string new_img_way, int new_item_level = 0) : Item(new_item_level, potion_weight, new_img_way)
{

}

Potion::~Potion()
{

}

