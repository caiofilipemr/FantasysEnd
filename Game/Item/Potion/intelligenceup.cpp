#include "intelligenceup.h"
#include "log.h"

std::string IntelligenceUP::int_img_way = "Inventory/Items/intelligenceup.png";

IntelligenceUP::IntelligenceUP() : Potion(int_img_way, "INTELLIGENCE", 0)
{

}

IntelligenceUP::~IntelligenceUP()
{

}

void IntelligenceUP::doEffect(Player &player)
{
    player.addIntelligence(item_level / 2 + 1);
    string log("ADD ");
    log += ((item_level / 2 + 1) + '0');
    log += " POINTS OF INTELLIGENCE";
    Log::setLog(log);
}

void IntelligenceUP::setImgWay(std::string new_img_way)
{
    int_img_way = new_img_way;
}

