#ifndef BARBARO_H
#define BARBARO_H

#include "Character/Player/Raca/human.h"
#include "Item/weapons/axe.h"

class Barbaro : public Human
{
private:
    static std::string barbaro_img_way;
    static std::string barbaro_img_battle;
public:
    static const int barb_strenght, barb_intelligence, barb_agility, barb_strenght_level, barb_intelligence_level, barb_agility_level, barb_bonus;

    Barbaro(int new_pos_i, int new_pos_j,
            Direction new_eye_direction);
    static void setImgWay(std::string new_img_way);
    static void setImgBattle(std::string new_img_battle);
    ~Barbaro();
};

#endif // BARBARO_H
