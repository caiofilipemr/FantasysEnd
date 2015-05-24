#ifndef DAGGER_H
#define DAGGER_H

#include "Item/weapon.h"

class Dagger : public Weapon
{
private:
    static const int dagger_damage, dagger_guard, dagger_weight;
    static std::string dagger_img_way;
public:
    Dagger(int new_item_level);
    ~Dagger();
    static void setImgWay(std::string new_img_way);
};

#endif // DAGGER_H
