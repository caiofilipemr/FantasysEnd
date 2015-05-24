#include "dagger.h"

const int Dagger::dagger_damage = 8;
const int Dagger::dagger_guard = 1;
const int Dagger::dagger_weight = 2;
std::string Dagger::dagger_img_way = "";

Dagger::Dagger(int new_item_level = 0) : Weapon(new_item_level, dagger_damage, dagger_guard, dagger_weight, dagger_img_way)
{

}

Dagger::~Dagger()
{

}

void Dagger::setImgWay(std::string new_img_way)
{
    dagger_img_way = new_img_way;
}

