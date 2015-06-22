#ifndef SHIELD_H
#define SHIELD_H

#include "item.h"
#include "commands.h"

class Shield : public Item
{
private:
    static const int guard_shield, shield_weight;
    int guard;
    static std::string shield_img_way;
public:
    Shield(int new_item_level);
    ~Shield();
    int getGuard();
    std::vector<Commands *> getCommands();
    static void setImgWay(std::string new_img_way);
    Information getInfos();
};

#endif // SHIELD_H
