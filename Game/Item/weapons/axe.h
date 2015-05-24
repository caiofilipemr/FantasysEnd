#ifndef AXE_H
#define AXE_H

#include "Item/weapon.h"

class Axe : public Weapon
{
private:
    static const int axe_damage, axe_guard, axe_weight;
    static std::string axe_img_way;
public:
    Axe(int new_item_level);
    ~Axe();
    static void setImgWay(std::string new_img_way);
};

#endif // AXE_H
