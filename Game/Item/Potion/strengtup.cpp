#include "strengtup.h"
#include "log.h"

std::string StrengtUP::strengt_img_way = "Inventory/Items/strenghtup.png";

StrengtUP::StrengtUP() : Potion(strengt_img_way, "STRENGHT", 0)
{

}

StrengtUP::~StrengtUP()
{

}

void StrengtUP::doEffect(Player &player)
{
    player.addStrenght(item_level / 2 + 1);
    string log("ADD ");
    log += ((item_level / 2 + 1) + '0');
    log += " POINTS OF STRENGHT";
    Log::setLog(log);
}

void StrengtUP::setImgWay(std::string new_img_way)
{
    strengt_img_way = new_img_way;
}

