#ifndef HEALFMP_H
#define HEALFMP_H

#include "potion.h"

class HealfMP : public Potion
{
private:
    static const int mp_heal;
    static std::string healfmp_img_way;
public:
    HealfMP();
    ~HealfMP();
    void doEffect(Player & player);
    static void setImgWay(std::string new_img_way);
};

#endif // HEALFMP_H
