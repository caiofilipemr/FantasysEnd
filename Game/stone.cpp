#include "stone.h"
#include "Character/Player/player.h"

const int Stone::hp = 200;
std::string Stone::stone_img_way = "Images/stone1.png";
Stone::Stone(int new_pos_i, int new_pos_j) : Object(new_pos_i, new_pos_j, stone_img_way)
{
    hp_var = hp;
}

Stone::~Stone()
{

}

void Stone::interate(Player * interate_player)
{
    hp_var = hp_var - interate_player->attack();
    if (hp_var < 1){
        throw BROKEN_STONE;
    }
}

void Stone::setImgWay(std::string new_img_way)
{
    stone_img_way = new_img_way;
}

