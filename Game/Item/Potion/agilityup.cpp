#include "agilityup.h"

std::string AgilityUP::agility_img_way = "Inventory/Items/agilityup.png";

AgilityUP::AgilityUP() : Potion(agility_img_way, "AGILITY", 0)
{

}

AgilityUP::~AgilityUP()
{

}

void AgilityUP::doEffect(Player &player)
{
    player.addAgility(item_level / 2 + 1);
}

void AgilityUP::setImgWay(std::string new_img_way)
{
    agility_img_way = new_img_way;
}

