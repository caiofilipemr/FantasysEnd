#ifndef HUMAN_H
#define HUMAN_H

#include "Character/Player/player.h"

class Human : public Player
{
public:
    Human(Weapon *new_weapon,
          int new_pos_i, int new_pos_j,
          std::string new_img_way, Direction new_eye_direction);
    ~Human();
private:
    static const int human_accuracy, human_dodge, human_range_damage, human_critical;

};

#endif // HUMAN_H
