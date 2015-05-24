#ifndef STONE_H
#define STONE_H

#include "globalfunctions.h"
#include "Enums.h"
#include "object.h"

class Stone : private Object
{
private:
    static const int hp ;
    int hp_var;
public:
    Stone(int new_pos_i, int new_pos_j, std::string new_img_way);
    ~Stone();
    void defense(int attack);
    //void addHP(int hp);
};

#endif // STONE_H
