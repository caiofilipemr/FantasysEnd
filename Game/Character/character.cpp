#include "character.h"

const int Character::limit = 16;

Character::Character(int new_speed, int new_accuracy,
                     int new_dodge, int new_range_damage,
                     int new_critical, int new_pos_i,
                     int new_pos_j, std::string new_img_way,
                     string new_img_battle, Direction new_eye_direction) : Object(new_pos_i, new_pos_j, new_img_way), speed(new_speed),
                                      accuracy(new_accuracy), dodge(new_dodge),
                                      range_damage(new_range_damage), critical(new_critical),
                                      walk_direction(SLEEP), eye_direction(new_eye_direction), cont(0), is_walking(false), img_battle(new_img_battle)
{
}

int Character::attack()
{
    int rand = 0;
    if ((random(100) + 1) > (this->accuracy))
        throw MISS;
    int dam_min = damage - range_damage;
    int dam_max = damage + range_damage;
    if ((rand = (random(100) + 1)) > (this->critical))
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
            throw CHARACTER_DIE;
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

int Character::getHPMax()
{
    return hp_max;
}

int Character::getMP()
{
    return mp;
}

int Character::getMPMax()
{
    return mp_max;
}

int Character::getGuard()
{
    return guard;
}

void Character::setDirection(Direction new_direction)
{
    walk_direction = new_direction;
}

void Character::setEyeDirection(Direction new_eye_direction)
{
    eye_direction = new_eye_direction;
}

Direction Character::getDirection()
{
    return walk_direction;
}

Direction Character::getEyeDirection()
{
    return eye_direction;
}

void Character::update(Map *my_map)
{
    if (is_walking) {
        if (cont < limit)
            cont++;
        else {
            is_walking = false;
            cont = 0;
        }
    }
    else {
        //if (walk_direction != SLEEP/* && !my_map->hasColision(Cordenates(this->pos_i, this->pos_j) + walk_direction)*/) { //Se vai andar para algum lugar e se esse lugar não tiver colisão, então:
            is_walking = true;
            this->walk();
            my_map->updateColision(this);
        //}
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

string Character::getImgBatlle()
{
    return img_battle;
}

int Character::getLimit()
{
    return limit;
}

