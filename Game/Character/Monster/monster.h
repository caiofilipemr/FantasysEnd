#ifndef MONSTER_H
#define MONSTER_H

#include "Character/character.h"

class Monster : public Character
{
protected:
    int drop_xp, monster_level;
    Inventory *drop;

    void move();
public:
    Monster(int new_speed, int new_accuracy,
            int new_dodge, int new_range_damage,
            int new_critical, int new_pos_i,
            int new_pos_j, std::string new_img_way,
            Direction new_eye_direction);
    int getDropXP();
    int getMonsterLevel();
    Inventory *getDrop();
};

#endif // MONSTER_H
