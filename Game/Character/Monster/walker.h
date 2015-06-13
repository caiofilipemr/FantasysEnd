#ifndef WALKER_H
#define WALKER_H

#include "Character/Monster/monster.h"

class Walker : public Monster
{
private:
     static const int accuracy_walker, dodge_walker, range_damage_walker, critical_walker;
     static const int hp_walker, mp_walker, damage_walker, guard_walker;
     static const int hp_variacao, mp_variacao, damage_variacao, guard_variacao;
public:
    Walker(int new_level_monster,
           int new_speed, int new_pos_i,
           int new_pos_j, std::string new_img_way,
           std::string new_img_battle,
           Direction new_eye_direction,
           int new_hp, int new_mp,
           int new_damage, int new_guard,
           int new_accuracy,int new_dodge,
           int new_range_damage, int new_critical,
           int new_hp_variacao, int new_mp_variacao,
           int new_damage_variacao, int new_guard_variacao);
    Walker(int new_level_monster,
           int new_speed, int new_pos_i,
           int new_pos_j, std::string new_img_way,
           std::string new_img_battle,
           Direction new_eye_direction);
    void walk();
};

#endif // WALKER_H
