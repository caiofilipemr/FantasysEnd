#ifndef SHIELD_H
#define SHIELD_H

#include "item.h"

class Shield:private Item
{
private:
    static const int guard_shield, shield_weight;
    int guard;
public:
    Shield(std::string new_img_way, int new_item_level);
    ~Shield();
    int getGuard();
};

#endif // SHIELD_H
