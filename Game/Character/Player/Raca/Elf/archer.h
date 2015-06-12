#ifndef ARCHER_H
#define ARCHER_H

#include "Character/Player/Raca/elf.h"
#include "Item/weapons/bow.h"

class Archer : public Elf
{
private:
    static const int arc_strenght, arc_agility, arc_intelligence, arc_strenght_level, arc_agility_level, arc_intelligence_level, arc_bonus;
    static std::string archer_img_way;
    static std::string archer_img_battle;
public:
    Archer(int new_pos_i, int new_pos_j,
           Direction new_eye_direction);
    static void setImgWay(std::string new_img_way);
    static void setImgBattle(std::string new_img_battle);
};

#endif // ARCHER_H
