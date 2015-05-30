#include "stalker.h"

void Stalker::stalk(int end_i, int end_j)
{
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
}

Stalker::Stalker(int new_hp, int new_mp,
                 int new_damage, int new_guard,
                 int new_speed, int new_accuracy,
                 int new_dodge, int new_range_damage,
                 int new_critical, int new_pos_i,
                 int new_pos_j, std::string new_img_way,
                 Direction new_eye_direction = DOWN) : Walker(new_hp, new_mp,
                                                              new_damage, new_guard,
                                                              new_speed, new_accuracy,
                                                              new_dodge, new_range_damage,
                                                              new_critical, new_pos_i,
                                                              new_pos_j,new_img_way ,new_eye_direction)
{
    old_end_i = old_end_j = -1;
}

void Stalker::update()
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
        if (walk_direction != SLEEP) {
            is_walking = true;
            walkOrStalk();
        }
    }
}

void Stalker::walkOrStalk()
{
    int xb = this->pos_i - 5, xe = this->pos_i + 5, yb = this->pos_j - 5, ye = this->pos_j + 5;
    int end_i = player->getCordenates().i, end_j = player->getCordenates().j;
    if (hasPoint(end_i, end_j)) stalk(end_i, end_j);
    else walk();
}
