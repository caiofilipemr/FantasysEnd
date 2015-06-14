#ifndef SLEEPER_H
#define SLEEPER_H

#include "Character/Monster/monster.h"

class Sleeper : public Monster
{
private:
    static const int sleeper_speed;
    static const int accuracy_sleeper, dodge_sleeper, range_damage_sleeper, critical_sleeper;
    static const int hp_sleeper, mp_sleeper, damage_sleeper, guard_sleeper;
    static const int hp_variacao, mp_variacao, damage_variacao, guard_variacao;
public:
    Sleeper(int new_level_monster,
            int new_speed, int new_pos_i,
            int new_pos_j, std::string new_img_way,
            std::string new_img_battle,
            Direction new_eye_direction);
    void walk();
    int getCont();
    bool getIsWalking();
};

#endif // SLEEPER_H
