#ifndef STONE_H
#define STONE_H

#include "globalfunctions.h"
#include "Enums.h"
#include "object.h"

class Stone : public Object
{
private:
    static const int hp;
    int hp_var;
    static std::string stone_img_way;
public:
    Stone(int new_pos_i, int new_pos_j);
    ~Stone();
    void defense(int attack);
    static void setImgWay(std::string new_img_way);
    //void addHP(int hp);
};

#endif // STONE_H
