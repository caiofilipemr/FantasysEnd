#include "walker.h"

Walker::Walker(int new_hp, int new_mp,
               int new_damage, int new_guard,
               int new_speed, int new_accuracy,
               int new_dodge, int new_range_damage,
               int new_critical, int new_pos_i,
               int new_pos_j, std::string new_img_way,
               Direction new_eye_direction = DOWN) : Monster(new_hp, new_mp,
                                                             new_damage, new_guard,
                                                             new_speed, new_accuracy,
                                                             new_dodge, new_range_damage,
                                                             new_critical, new_pos_i,
                                                             new_pos_j, new_img_way,
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
    per[UP] = (chance[UP] / sum) * 100;
    chance[UP] = back_chance[UP];
    for(i = 1; i < 4; i++){
        per[i] = (chance[i] / sum) * 100 + per[i - 1];
        chance[i] = back_chance[i];
    }
    rand = random(per[RIGHT]);
    for( i = 0, logic = true; i < 4; i++)
        rand <= per[i] && logic ? setDirection(Direction(i)), logic = false : chance[i]++;

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
