#ifndef STALKER_H
#define STALKER_H

#include "Character/Monster/walker.h"
#include "globalfunctions.h"
#include "macros.h"

class Stalker : public Walker
{
private:
    std::stack<Direction> directions_stack;
    int old_end_i, old_end_j;
    void stalk(int end_i, int end_j);
    static const int accuracy_stalker, dodge_stalker, range_damage_stalker, critical_stalker;
    static const int hp_stalker, mp_stalker, damage_stalker, guard_stalker;
    static const int hp_vari, mp_vari, damage_vari, guard_vari;
public:
    Stalker(int new_level_monster,
            int new_speed, int new_pos_i,
            int new_pos_j, std::string new_img_way,
            std::string new_img_battle,
            Direction new_eye_direction);
    void update(Map *my_map);
    void walkOrStalk();
};

#endif // STALKER_H
