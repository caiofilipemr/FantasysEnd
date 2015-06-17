#include "item.h"

Item::Item(int new_item_level, int new_weigh, std::string new_img_way) : img_way(new_img_way)
{
    if (!new_item_level) {
        new_item_level = random(100) + 1;
                ;
        if (new_item_level <= 35) {
            new_item_level = 1;
        } else if (new_item_level <= 65) {
            new_item_level = 2;
        } else if (new_item_level <= 85) {
            new_item_level = 3;
        } else if (new_item_level <= 95) {
            new_item_level = 4;
        } else {
            new_item_level = 5;
        }
    }
    item_level = new_item_level;
    weight = new_weigh * item_level;
}

Item::~Item()
{

}

std::string Item::getImg_way()
{
   return img_way;
}

int Item::getWeight()
{
    return weight;
}

int Item::getItemId()
{
    return id;
}

int Item::getLevelItem()
{
    return item_level;
}

