#include "weapon.h"

Weapon::Weapon(int new_item_level, int new_damage,
               int new_guard, int new_weight, std::string new_img_way) : Item(new_item_level, new_weight, new_img_way), damage(new_damage), guard(new_guard)
{

}

Weapon::~Weapon()
{

}

int Weapon::getGuard()
{
    return guard;
}

int Weapon::getDamage()
{
    return damage;
}

std::vector<Commands *> Weapon::getCommands()
{
    std::vector<Commands *> list_of_cmd;
    list_of_cmd.push_back(new EquipWeapon(this));
    list_of_cmd.push_back(new Drop(this));
    return list_of_cmd;
}

