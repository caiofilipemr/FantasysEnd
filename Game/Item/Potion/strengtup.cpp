#include "strengtup.h"
std::string StrengtUP::strengt_img_way = "";

StrengtUP::StrengtUP() : Potion(strengt_img_way, 0)
{

}

StrengtUP::~StrengtUP()
{

}

void StrengtUP::doEffect(Player &player)
{
    player.addStrenght(item_level / 2 + 1);
}

void StrengtUP::setImgWay(std::string new_img_way)
{
    strengt_img_way = new_img_way;
}

