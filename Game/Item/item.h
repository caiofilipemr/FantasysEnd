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
    std::string img_way, item_name;
public:
    Item(int new_item_level, int new_weigh, std::string new_img_way, std::string new_item_name);
    virtual ~Item();
    std::string getImg_way();
    int getWeight();
    int getItemId();
    int getLevelItem();
    std::string getItemName();
    virtual std::vector<Commands *> getCommands() = 0;
    virtual Information getInfos() = 0;
};

#endif // ITEM_H
