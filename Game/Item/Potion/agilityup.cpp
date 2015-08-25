#include "agilityup.h"
#include "log.h"

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
    string log("ADD ");
    log += ((item_level / 2 + 1) + '0');
    log += " POINTS OF AGILITY";
    Log::setLog(log);
}

void AgilityUP::setImgWay(std::string new_img_way)
{
    agility_img_way = new_img_way;
}

