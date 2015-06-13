#include "stalker.h"

const int Stalker::accuracy_stalker = 90;
const int Stalker::dodge_stalker = 7;
const int Stalker::range_damage_stalker = 9;
const int Stalker::critical_stalker = 5;

const int Stalker::hp_stalker = 1350;
const int Stalker::mp_stalker = 100;
const int Stalker::damage_stalker = 78;
const int Stalker::guard_stalker = 8;

const int Stalker::hp_vari = 57;
const int Stalker::mp_vari = 10;
const int Stalker::damage_vari = 10;
const int Stalker::guard_vari = 2;

void Stalker::stalk(int end_i, int end_j)
{
    try {
        if (end_i != old_end_i || end_j != old_end_j) {
            directions_stack = shortPass(pos_i, pos_j, end_i, end_j);
            old_end_i = end_i;
            old_end_j = end_j;
        }
        for (int i = 0; i < speed; i++) {
            setDirection(directions_stack.top());
            setEyeDirection(directions_stack.top());
            directions_stack.pop();
            move();
        }
    } catch (const char * err) {
        cerr << err;
        walk();
    }
}

Stalker::Stalker(int new_level_monster,
                 int new_speed, int new_pos_i,
                 int new_pos_j, std::string new_img_way,
                 string new_img_battle,
                 Direction new_eye_direction = DOWN) : Walker(new_level_monster,
                                                              new_speed, new_pos_i,
                                                              new_pos_j, new_img_way,
                                                              new_img_battle ,new_eye_direction,
                                                              hp_stalker, mp_stalker, damage_stalker,
                                                              guard_stalker, accuracy_stalker, dodge_stalker,
                                                              damage_stalker, critical_stalker, hp_vari,
                                                              mp_vari, damage_vari, guard_vari)
{
    old_end_i = old_end_j = -1;
}

void Stalker::update(Map * my_map)
{
    if (all_is_walking) {
        if (all_is_walking < limit)
            monsterUpdate();
    }
    else {
            monsterUpdate();
            walkOrStalk();
            my_map->updateColision(this);
    }
}

void Stalker::walkOrStalk()
{
    int xb = this->pos_i - 5, xe = this->pos_i + 5, yb = this->pos_j - 5, ye = this->pos_j + 5;
    int end_i = player->getCordenates().i, end_j = player->getCordenates().j;
    if (hasPoint(end_i, end_j)) stalk(end_i, end_j);
    else walk();
}
