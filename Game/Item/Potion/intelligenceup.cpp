#include "intelligenceup.h"
std::string IntelligenceUP::int_img_way = "";

IntelligenceUP::IntelligenceUP() : Potion(int_img_way, 0)
{

}

IntelligenceUP::~IntelligenceUP()
{

}

void IntelligenceUP::doEffect(Player &player)
{
    player.addIntelligence(item_level / 2 + 1);
}

void IntelligenceUP::setImgWay(std::string new_img_way)
{
    int_img_way = new_img_way;
}

