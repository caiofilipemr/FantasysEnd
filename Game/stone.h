#ifndef STONE_H
#define STONE_H

//#include "globalfunctions.h"
//#include "Enums.h"
#include "map.h"

class Stone : public Object
{
private:
    static const int hp;
    int hp_var;
    static std::string stone_img_way,broken_stone_img;
public:
    Stone(int new_pos_i, int new_pos_j);
    ~Stone();
    void interate(Player * interate_player);
    static void setImgWay(std::string new_img_way);
    static std::string getImgBrokenStone();
    //void addHP(int hp);
};

#endif // STONE_H
