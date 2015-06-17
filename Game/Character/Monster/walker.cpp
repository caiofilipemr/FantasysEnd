#include "walker.h"

const int Walker::accuracy_walker = 92;
const int Walker::dodge_walker = 5;
const int Walker::range_damage_walker = 7;
const int Walker::critical_walker = 8;

const int Walker::hp_walker = 1400;
const int Walker::mp_walker = 100;
const int Walker::damage_walker = 99;
const int Walker::guard_walker = 10;

const int Walker::hp_variacao = 47;
const int Walker::mp_variacao = 10;
const int Walker::damage_variacao = 7;
const int Walker::guard_variacao = 4;

//const - variacao + rand((const + variacao) - (const - variacao) + 1)
Walker::Walker(int new_level_monster,
               int new_speed, int new_pos_i,
               int new_pos_j, std::string new_img_way, string new_img_battle,
               int new_hp, int new_mp,
               int new_damage, int new_guard,
               int new_accuracy, int new_dodge,
               int new_range_damage, int new_critical,
               int new_hp_variacao, int new_mp_variacao,
               int new_damage_variacao, int new_guard_variacao,
               Direction new_eye_direction = DOWN) : Monster (new_level_monster,
                                                             (new_hp - new_hp_variacao + random((new_hp + new_hp_variacao) - (new_hp - new_hp_variacao) +1)),
                                                             (new_mp - new_mp_variacao + random((new_mp + new_mp_variacao) - (new_mp - new_mp_variacao) +1)),
                                                             (new_damage - new_damage_variacao + random((new_damage + new_damage_variacao) - (new_damage - new_damage_variacao) +1)) * new_level_monster,
                                                             (new_guard - new_guard_variacao + random((new_guard + new_guard_variacao) - (new_guard - new_guard_variacao) +1)),
                                                              new_speed, new_accuracy,
                                                              new_dodge, new_range_damage,
                                                              new_critical, new_pos_i,
                                                              new_pos_j, new_img_way,
                                                              new_img_battle,
                                                              new_eye_direction)
{
    chance[UP] = chance[DOWN] = chance[LEFT] = chance[RIGHT] = 1;
    back_chance[UP] = back_chance[DOWN] = back_chance[LEFT] = back_chance[RIGHT] = 0;
}

Walker::Walker(int new_level_monster,
               int new_speed, int new_pos_i,
               int new_pos_j, string new_img_way,
               string new_img_battle,
               Direction new_eye_direction = DOWN): Monster (new_level_monster,
                                                      (hp_walker - hp_variacao + random((hp_walker + hp_variacao) - (hp_walker - hp_variacao) +1)),
                                                      (hp_walker - mp_variacao + random((hp_walker + mp_variacao) - (hp_walker - mp_variacao) +1)),
                                                      (damage_walker - damage_variacao + random((damage_walker + damage_variacao) - (damage_walker - damage_variacao) +1)) * new_level_monster,
                                                      (guard_walker - guard_variacao + random((guard_walker + guard_variacao) - (guard_walker - guard_variacao) +1)),
                                                       new_speed, accuracy_walker,
                                                       dodge_walker, range_damage_walker,
                                                       critical_walker, new_pos_i,
                                                       new_pos_j, new_img_way,
                                                       new_img_battle,
                                                       new_eye_direction)
{
    chance[UP] = chance[DOWN] = chance[LEFT] = chance[RIGHT] = 1;
    back_chance[UP] = back_chance[DOWN] = back_chance[LEFT] = back_chance[RIGHT] = 0;
}

void Walker::walk()
{
    //falta verificar se o change nao esta muito grande, para nao dar estouro
    int i, rand;
    float sum;
    i = sum = 0;
    bool logic;
    for(i = 0; i < 4; i++){
        back_chance[i] = chance[i];
        chance[i] = chance[i]*int(can_go[i]);
        sum += chance[i];
    }
    per[DOWN] = (chance[DOWN] / sum) * 100;
    chance[DOWN] = back_chance[DOWN];
    for(i = 1; i < 4; i++){
        per[i] = (chance[i] / sum) * 100 + per[i - 1];
        chance[i] = back_chance[i];
    }
    rand = random(per[UP]);
    for( i = 0, logic = true; i < 4; i++)
        rand <= per[i] && logic ? setDirection(Direction(i)), setEyeDirection(Direction(i)), logic = false : chance[i]++;

    move();

//    if (rand <= per[i]) {
//        setDirection(UP);
//        increase(DOWN, RIGHT, LEFT)
//    } else if (rand <= per[i]) {
//        setDirection(DOWN);
//        increase(UP, RIGHT, LEFT)
//    } else if (rand <= per[i]) {
//        setDirection(LEFT);
//        increase(UP, DOWN, RIGHT)
//    } else {
//        setDirection(RIGHT);
//        increase(UP, DOWN, LEFT)
//    }
}
