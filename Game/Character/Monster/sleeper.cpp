#include "sleeper.h"

const int Sleeper::sleeper_speed = 0;

Sleeper::Sleeper(int new_hp, int new_mp,
                 int new_damage, int new_guard,
                 int new_speed, int new_accuracy,
                 int new_dodge, int new_range_damage,
                 int new_critical, int new_pos_i,
                 int new_pos_j, std::string new_img_way,
                 Direction new_eye_direction = DOWN) : Monster(new_hp, new_mp,
                                                               new_damage, new_guard,
                                                               new_speed, new_accuracy,
                                                               new_dodge, new_range_damage,
                                                               new_critical, new_pos_i,
                                                               new_pos_j, new_img_way,
                                                               new_eye_direction)
{
}

void Sleeper::walk()
{
    eye_direction = Direction(random(4));
    walk_direction = SLEEP;
}

int Sleeper::getCont()
{
    return 0;
}

bool Sleeper::getIsWalking()
{
    return false;
}
