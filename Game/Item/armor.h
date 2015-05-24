#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"


class Armor : public Item
{
private:
    static const int guard_armor, armor_weight;
    int guard;
public:
    Armor(std::string new_img_way, int new_item_level);
    ~Armor();
    int getGuard();
};

#endif // ARMOR_H
