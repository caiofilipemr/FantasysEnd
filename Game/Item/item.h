#ifndef ITEM_H
#define ITEM_H

class Commands;

#include "globalfunctions.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
//#include "commands.h"

class Item
{
protected:
    int id, weight, item_level;
    std::string img_way;
public:
    Item(int new_item_level, int new_weigh, std::string new_img_way);
    virtual ~Item();
    int getWeight();
    int getItemId();
    int getLevelItem();
    virtual std::vector<Commands *> getCommands() = 0;
};

#endif // ITEM_H
