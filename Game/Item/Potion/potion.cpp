#include "potion.h"

const int Potion::potion_weight = 1;

Potion::Potion(std::string new_img_way, std::string new_item_name, int new_item_level = 0) : Item(new_item_level, potion_weight, new_img_way, new_item_name + " POTION")
{

}

Potion::~Potion()
{

}

std::vector<Commands *> Potion::getCommands()
{
    std::vector<Commands *> list_of_cmd;
    list_of_cmd.push_back(new Consume(this));
    list_of_cmd.push_back(new Drop(this));
    return list_of_cmd;
}

Information Potion::getInfos()
{
    Information info(2);
    info.addInfo("WEIGHT", weight);
    info.addInfo("ITEM LEVEL", item_level);
    return info;
}

