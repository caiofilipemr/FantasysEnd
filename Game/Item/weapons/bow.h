#ifndef BOW_H
#define BOW_H

#include "Item/weapon.h"

class Bow : public Weapon
{
private:
    static const int bow_damage, bow_guard, bow_weight;
    static std::string bow_img_way;
public:
    Bow(int new_item_level);
    ~Bow();
    static void setImgWay(std::string new_img_way);
};

#endif // BOW_H
