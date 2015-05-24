#ifndef TROLL_H
#define TROLL_H

#include "Character/Player/Raca/orcs.h"
#include "Item/weapons/mace.h"

class Troll : public Orc
{
private:
    static const int troll_strenght, troll_agility, troll_intelligence, troll_strenght_level, troll_agility_level, troll_intelligence_level, troll_bonus;
    static std::string troll_img_way;
public:
    Troll(int new_pos_i, int new_pos_j,
          Direction new_eye_direction);
    static void setImgWay(std::string new_img_way);
    ~Troll();
};

#endif // TROLL_H
