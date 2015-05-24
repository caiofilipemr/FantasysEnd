#ifndef ROD_H
#define ROD_H

#include "Item/weapon.h"

class Rod : public Weapon
{
private:
    static const int rod_damage, rod_guard, rod_weight;
    static std::string rod_img_way;
public:
    Rod(int new_item_level);
    ~Rod();
    static void setImgWay(std::string new_img_way);
};

#endif // ROD_H
