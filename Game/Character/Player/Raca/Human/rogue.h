#ifndef ROGUE_H
#define ROGUE_H

#include "Character/Player/Raca/human.h"
#include "Item/weapons/dagger.h"

class Rogue : public Human
{
private:
    static const int rog_strenght, rog_intelligence, rog_agility, rog_strenght_level, rog_intelligence_level, rog_agility_level, rog_bonus;
    static std::string rogue_img_way;
public:
    Rogue(int new_pos_i, int new_pos_j,
          Direction new_eye_direction);
    static void setImgWay(std::string new_img_way);
    ~Rogue();
};

#endif // ROGUE_H
