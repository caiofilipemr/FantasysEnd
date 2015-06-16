#include "armor.h"

const int Armor::guard_armor = 2; //Multiplicador de pontos de GUARD
const int Armor::armor_weight = 3;
std::string Armor::armor_img_way = "Inventory/Items/armor.png";

Armor::Armor(int new_item_level = 0) : Item(new_item_level, armor_weight, armor_img_way)
{
    guard = item_level * guard_armor;
}

Armor::~Armor()
{

}

int Armor::getGuard()
{
    return guard;
}

std::vector<Commands *> Armor::getCommands()
{
    std::vector<Commands *> list_of_cmd;
    list_of_cmd.push_back(new EquipArmor(this));
    list_of_cmd.push_back(new Drop(this));
    return list_of_cmd;
}

void Armor::setImgWay(string new_img_way)
{
    armor_img_way = new_img_way;
}

