#ifndef POTION_H
#define POTION_H

#include "Item/item.h"
#include "Character/Player/player.h"
#include "commands.h"

class Potion : public Item
{
private:
    static const int potion_weight;
public:
    Potion(std::string new_img_way, std::string new_item_name, int new_item_level);
    ~Potion();
    virtual void doEffect(Player & player) = 0;
    std::vector<Commands *> getCommands();
    Information getInfos();
};

#endif // POTION_H
