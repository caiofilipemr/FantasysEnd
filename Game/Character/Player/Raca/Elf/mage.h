#ifndef MAGE_H
#define MAGE_H

#include "Character/Player/Raca/elf.h"
#include "Item/weapons/rod.h"

class Mage : public Elf
{
private:
    static const int mage_strenght, mage_agility, mage_intelligence, mage_strenght_level, mage_agility_level, mage_intelligence_level, mage_bonus;
    static std::string mage_img_way;
    static std::string mage_img_battle;
public:
    Mage(int new_pos_i, int new_pos_j,
         Direction new_eye_direction);
    static void setImgWay(std::string new_img_way);
    static void setImgBattle(std::string new_img_battle);
};

#endif // MAGE_H
