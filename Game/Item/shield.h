#ifndef SHIELD_H
#define SHIELD_H

#include "item.h"
#include "commands.h"

class Shield : public Item
{
private:
    static const int guard_shield, shield_weight;
    int guard;
public:
    Shield(std::string new_img_way, int new_item_level);
    ~Shield();
    int getGuard();
    std::vector<Commands *> getCommands();
};

#endif // SHIELD_H
