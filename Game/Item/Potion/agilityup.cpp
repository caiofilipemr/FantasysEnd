#include "agilityup.h"

std::string AgilityUP::agility_img_way = " ";

AgilityUP::AgilityUP() : Potion(agility_img_way, 0)
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

