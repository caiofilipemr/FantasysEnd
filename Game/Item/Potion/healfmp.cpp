#include "healfmp.h"

const int HealfMP::mp_heal = 50; //Multiplicador de pontos de cura de MP (MANA POINTS)
std::string HealfMP::healfmp_img_way = "Inventory/Items/healmp.png";

HealfMP::HealfMP() : Potion(healfmp_img_way, 0)
{

}

HealfMP::~HealfMP()
{

}

void HealfMP::doEffect(Player &player)
{
    player.addMP(mp_heal * item_level);
}

void HealfMP::setImgWay(std::string new_img_way)
{
    healfmp_img_way = new_img_way;
}

