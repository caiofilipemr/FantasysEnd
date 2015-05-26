#include "character.h"

const int Character::limit = 16;

Character::Character(int new_speed, int new_accuracy,
                     int new_dodge, int new_range_damage,
                     int new_critical, int new_pos_i,
                     int new_pos_j, std::string new_img_way, Direction new_eye_direction) : Object(new_pos_i, new_pos_j, new_img_way), speed(new_speed),
                                      accuracy(new_accuracy), dodge(new_dodge),
                                      range_damage(new_range_damage), critical(new_critical),
                                      walk_direction(SLEEP), eye_direction(new_eye_direction), cont(0), is_walking(false)
{
}

int Character::attack()
{
    if ((random(100) + 1) > accuracy)
        throw MISS;
    int dam_min = (damage - range_damage), dam_max = (damage + range_damage);
    if ((random(100) + 1) > critical)
        return (random(dam_max - dam_min + 1) + dam_min);
    return (random(dam_max - dam_min + 1) + dam_min) * 2;
}

void Character::defense(int attack)
{
    if ((random(100) + 1) <= dodge)
        throw DODGE;
    if((attack - guard) > 0) {
        hp = hp - (attack - guard);
        if (hp < 1)
            throw PLAYER_DIE;
    }
}

void Character::addHP(int hp_plus)
{
    if (hp + hp_plus > hp_max)
        hp = hp_max;
    else
        hp += hp_plus;
}

void Character::addMP(int mp_plus)
{
    if (mp + mp_plus > mp_max)
        mp = mp_max;
    else
        mp += mp_plus;
}

int Character::getHP()
{
    return hp;
}

int Character::getMP()
{
    return mp;
}

int Character::getGuard()
{
    return guard;
}

void Character::setDirection(Direction new_direction)
{
    walk_direction = new_direction;
}

void Character::update()
{
    if (is_walking) {
        if (cont < limit)
            cont ++;
        else {
            is_walking = false;
            cont = 0;
        }
    }
    else {
        if (walk_direction != SLEEP) {
            is_walking = true;
            walk();
        }
    }
}

int Character::getCont()
{
    return cont;
}

bool Character::getIsWalking()
{
    return is_walking;
}

