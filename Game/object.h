#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "cordenates.h"

class Player;

class Object
{
protected:
    int pos_i, pos_j;
    const std::string img_way;
public:
    Object(int new_pos_i, int new_pos_j, std::string new_img_way);
    virtual ~Object();
    Cordenates getCordenates();
    std::string getImgWay();
    virtual void interate(Player *) {}
};

#endif // OBJECT_H
