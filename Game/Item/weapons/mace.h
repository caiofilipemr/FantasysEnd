#ifndef MACE_H
#define MACE_H

#include "Item/weapon.h"

class Mace : public Weapon
{
private:
    static const int mace_damage, mace_guard, mace_weight;
    static std::string mace_img_way;
public:
    Mace(int new_item_level);
    ~Mace();
    static void setImgWay(std::string new_img_way);
};

#endif // MACE_H
