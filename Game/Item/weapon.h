#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : private Item
{
private:
    int damage, guard;
public:
    Weapon(int new_item_level, int new_damage,
           int new_guard, int new_weight,
           std::string new_img_way );
    ~Weapon();
    int getGuard();
    int getDamage();
};

#endif // WEAPON_H
