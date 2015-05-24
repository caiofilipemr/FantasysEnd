#ifndef CHEST_H
#define CHEST_H

#include "object.h"

class Chest : private Object
{
private:
    Item * item;
    void randItem(int rand);
public:
    Chest(int new_pos_i, int new_pos_j, std::string new_img_way);
    ~Chest();
    Item getItem();
};

#endif // CHEST_H
