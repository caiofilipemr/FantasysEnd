#include "stone.h"
const int Stone::hp = 100;
Stone::Stone(int new_pos_i, int new_pos_j, std::string new_img_way) : Object(new_pos_i, new_pos_j, new_img_way)
{
    hp_var = hp;
}

Stone::~Stone()
{

}

void Stone::defense(int attack)
{
    hp_var = hp_var - attack;
    if (hp_var < 1){
        Cordenates c(this->pos_i, this->pos_j);
        throw c;
    }
}

