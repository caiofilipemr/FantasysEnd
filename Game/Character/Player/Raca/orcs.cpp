#include "orcs.h"

const int Orc::orc_accuracy = 97;
const int Orc::orc_dodge = 3;
const int Orc::orc_range_damage = 3;
const int Orc::orc_critical= 5;

Orc::Orc(Weapon *new_weapon,
         int new_pos_i, int new_pos_j, std::string new_img_way, string new_img_battle,
         Direction new_eye_direction = DOWN) : Player(new_weapon,
                                                orc_accuracy, orc_dodge,
                                                orc_range_damage, orc_critical,
                                                new_pos_i, new_pos_j, new_img_way,
                                                new_img_battle,
                                                new_eye_direction)
{

}

Orc::~Orc()
{

}

