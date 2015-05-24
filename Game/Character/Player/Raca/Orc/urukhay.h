#ifndef URUKHAY_H
#define URUKHAY_H

#include "Character/Player/Raca/orcs.h"
#include "Item/weapons/sword.h"

class Urukhay : public Orc
{
private:
    static const int hay_strenght, hay_agility, hay_intelligence, hay_strenght_level, hay_agility_level, hay_intelligence_level, hay_bonus;
    static std::string urukhay_img_way;
public:
    Urukhay(int new_pos_i, int new_pos_j,
            Direction new_eye_direction);
    static void setImgWay(std::string new_img_way);
    ~Urukhay();
};

#endif // URUKHAY_H
