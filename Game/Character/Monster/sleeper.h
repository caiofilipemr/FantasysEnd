#ifndef SLEEPER_H
#define SLEEPER_H

#include "Character/Monster/monster.h"

class Sleeper : public Monster
{
private:
    static const int sleeper_speed;
public:
    Sleeper(int new_hp, int new_mp,
            int new_damage, int new_guard,
            int new_speed, int new_accuracy,
            int new_dodge, int new_range_damage,
            int new_critical, int new_pos_i,
            int new_pos_j, std::string new_img_way,
            Direction new_eye_direction);
    void walk();
    int getCont();
};

#endif // SLEEPER_H
