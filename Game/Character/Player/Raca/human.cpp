#include "human.h"

const int Human::human_accuracy = 93;
const int Human::human_dodge = 10;
const int Human::human_range_damage = 5;
const int Human::human_critical = 7;

Human::Human(Weapon *new_weapon,
             int new_pos_i, int new_pos_j, std::string new_img_way,
             std::string new_img_battle,
             Direction new_eye_direction = DOWN) : Player(new_weapon,
                                                            human_accuracy, human_dodge,
                                                            human_range_damage, human_critical,
                                                            new_pos_i, new_pos_j,
                                                            new_img_way, new_img_battle, new_eye_direction)
{
}

Human::~Human()
{
}

