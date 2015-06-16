#ifndef HEALFHP_H
#define HEALFHP_H

#include "potion.h"

class HealfHP : public Potion
{
private:
    static const int hp_heal;
    static std::string healfhp_img_way;
public:
    HealfHP();
    ~HealfHP();
    void doEffect(Player & player);
    static void setImgWay(std::string new_img_way);
};

#endif // HEALFHP_H
