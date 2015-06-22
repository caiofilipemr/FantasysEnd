#include "shield.h"

const int Shield::guard_shield = 1; //Multiplicador de pontos de SHIELD
const int Shield::shield_weight = 2;
std::string Shield::shield_img_way = "Inventory/Items/shield.png";

Shield::Shield(int new_item_level = 0) : Item(new_item_level, shield_weight, shield_img_way)
{
    guard = item_level * guard_shield;
}

Shield::~Shield()
{

}

int Shield::getGuard()
{
    return guard;
}

std::vector<Commands *> Shield::getCommands()
{
    std::vector<Commands *> list_of_cmd;
    list_of_cmd.push_back(new EquipShield(this));
    list_of_cmd.push_back(new Drop(this));
    return list_of_cmd;
}

void Shield::setImgWay(string new_img_way)
{
    shield_img_way = new_img_way;
}

Information Shield::getInfos()
{
    Information info(3);
    info.addInfo("WEIGHT", weight);
    info.addInfo("ITEM LEVEL", item_level);
    info.addInfo("GUARD", getGuard());
    return info;
}
