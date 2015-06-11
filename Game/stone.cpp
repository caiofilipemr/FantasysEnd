#include "stone.h"
const int Stone::hp = 100;
std::string Stone::stone_img_way = "Images/stone.png";
Stone::Stone(int new_pos_i, int new_pos_j) : Object(new_pos_i, new_pos_j, stone_img_way)
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

void Stone::setImgWay(std::string new_img_way)
{
    stone_img_way = new_img_way;
}

