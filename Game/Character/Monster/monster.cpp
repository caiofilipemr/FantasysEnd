#include "monster.h"

//BitBucketTeste

Monster::Monster(int new_hp, int new_mp,
                 int new_damage, int new_guard,
                 int new_speed, int new_accuracy,
                 int new_dodge, int new_range_damage,
                 int new_critical, int new_pos_i,
                 int new_pos_j, std::string new_img_way,
                 Direction new_eye_direction = DOWN) : Character(new_speed, new_accuracy,
                                                                   new_dodge, new_range_damage,
                                                                   new_critical, new_pos_i,
                                                                   new_pos_j, new_img_way, new_eye_direction), player(NULL)
{
    hp = hp_max = new_hp;
    mp = mp_max = new_mp;
    damage = new_damage;
    guard = new_guard;
}

int Monster::getDropXP()
{
    return drop_xp;
}

int Monster::getMonsterLevel()
{
    return monster_level;
}

Inventory *Monster::getDrop()
{
    Inventory *temp_drop = drop;
    drop = NULL;
    return temp_drop;
}

void Monster::setStalk(Object *player)
{
    this->player = player;
}

void Monster::move()
{
    switch (walk_direction) {
    case UP:
        pos_i--;
        break;
    case DOWN:
        pos_i++;
        break;

    case LEFT:
        pos_j--;
        break;

    case RIGHT:
        pos_j++;
        break;

    default:
        break;
    }
}

void Monster::setCanGo(bool * can)
{
    can_go = can;
}
