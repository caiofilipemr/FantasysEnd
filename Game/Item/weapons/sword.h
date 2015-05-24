#ifndef SWORD_H
#define SWORD_H

#include "Item/weapon.h"

class Sword : public Weapon
{
private:
    static const int sword_damage, sword_guard, sword_weight;
    static std::string sword_img_way;
public:
    Sword(int new_item_level);
    ~Sword();
    static void setImgWay(std::string new_img_way);
};

#endif // SWORD_H
