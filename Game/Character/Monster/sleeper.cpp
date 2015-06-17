#include "sleeper.h"

const int Sleeper::sleeper_speed = 0;

const int Sleeper::accuracy_sleeper = 95;
const int Sleeper::dodge_sleeper = 10;
const int Sleeper::range_damage_sleeper = 5;
const int Sleeper::critical_sleeper = 12;

const int Sleeper::hp_sleeper = 1650;
const int Sleeper::mp_sleeper = 100;
const int Sleeper::damage_sleeper = 120;
const int Sleeper::guard_sleeper = 12;

const int Sleeper::hp_variacao = 42;
const int Sleeper::mp_variacao = 10;
const int Sleeper::damage_variacao = 12;
const int Sleeper::guard_variacao = 3;
//const - variacao + rand((const + variacao) - (const - variacao) + 1)
Sleeper::Sleeper(int new_level_monster,
                 int new_speed, int new_pos_i,
                 int new_pos_j, std::string new_img_way,
                 string new_img_battle,
                 Direction new_eye_direction = DOWN) : Monster(new_level_monster,
                                                               (hp_sleeper - hp_variacao + random((hp_sleeper + hp_variacao) - (hp_sleeper - hp_variacao) +1)),
                                                               (mp_sleeper - mp_variacao + random((mp_sleeper + mp_variacao) - (mp_sleeper - mp_variacao) +1)),
                                                               (damage_sleeper - damage_variacao + random((damage_sleeper + damage_variacao) - (damage_sleeper - damage_variacao) +1)) * new_level_monster,
                                                               (guard_sleeper - guard_variacao + random((guard_sleeper + guard_variacao) - (guard_sleeper - guard_variacao) +1)),
                                                               new_speed, accuracy_sleeper,
                                                               dodge_sleeper, range_damage_sleeper,
                                                               critical_sleeper, new_pos_i,
                                                               new_pos_j, new_img_way,
                                                               new_img_battle,
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
