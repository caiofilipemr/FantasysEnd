#ifndef WALKER_H
#define WALKER_H

#include "Character/Monster/monster.h"

class Walker : public Monster
{
private:
    int per[4], chance[4], back_chance[4];
    bool *can_go;
public:
    Walker(int new_speed, int new_accuracy,
           int new_dodge, int new_range_damage,
           int new_critical, int new_pos_i,
           int new_pos_j, std::string new_img_way, Direction new_eye_direction);
    void setCanGo(bool *can);
    void walk();
};

#endif // WALKER_H
