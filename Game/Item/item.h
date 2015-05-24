#ifndef ITEM_H
#define ITEM_H

#include "globalfunctions.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

class Item
{
protected:
    int id, weight, item_level;
    std::string img_way;
public:
    Item(int new_item_level, int new_weigh, std::string new_img_way);
    ~Item();
    int getWeight();
    int getItemId();
    int getLevelItem();
};

#endif // ITEM_H
