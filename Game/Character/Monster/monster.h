#ifndef MONSTER_H
#define MONSTER_H

#include "Character/character.h"

class Monster : public Character
{
protected:
    int drop_xp, monster_level;
    Inventory *drop;
    Object *player;
    void move();
    int per[4], chance[4], back_chance[4];
    bool *can_go;
public:
    Monster(int new_hp, int new_mp,
            int new_damage, int new_guard,
            int new_speed, int new_accuracy,
            int new_dodge, int new_range_damage,
            int new_critical, int new_pos_i,
            int new_pos_j, std::string new_img_way,
            Direction new_eye_direction);
    virtual ~Monster() { }
    int getDropXP();
    int getMonsterLevel();
    Inventory *getDrop();
    void setStalk(Object *player);
    void setCanGo(bool *can);
    void die(Map * my_map);
};

#endif // MONSTER_H
