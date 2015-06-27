#ifndef WEAPON_H
#define WEAPON_H

#include "Item/item.h"
#include "commands.h"

class Weapon : public Item
{
protected:
    int damage, guard;
public:
    Weapon(int new_item_level, int new_damage,
           int new_guard, int new_weight,
           std::string new_img_way , string new_item_name);
    ~Weapon();
    int getGuard();
    int getDamage();
    std::vector<Commands *> getCommands();
    Information getInfos();
};

#endif // WEAPON_H
