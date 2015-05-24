#ifndef ORCS_H
#define ORCS_H

#include "Character/Player/player.h"

class Orc : public Player
{
private:
    static const int orc_accuracy, orc_dodge, orc_range_damage, orc_critical;
public:
    Orc(Weapon *new_weapon,
        int new_pos_i, int new_pos_j,
        std::string new_img_way, Direction new_eye_direction);
    ~Orc();
};

#endif // ORCS_H
