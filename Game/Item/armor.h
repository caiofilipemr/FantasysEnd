#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"
#include "commands.h"

class Armor : public Item
{
private:
    static const int guard_armor, armor_weight;
    int guard;
    static std::string armor_img_way;
public:
    Armor(int new_item_level);
    ~Armor();
    int getGuard();
    std::vector<Commands *> getCommands();
    static void setImgWay(std::string new_img_way);
};

#endif // ARMOR_H
