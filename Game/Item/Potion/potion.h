#ifndef POTION_H
#define POTION_H

#include "Item/item.h"
#include "Character/Player/player.h"

class Potion : public Item
{
private:
    static const int potion_weight;
public:
    Potion(std::string new_img_way, int new_item_level);
    ~Potion();
    virtual void doEffect(Player & player) = 0;
};

#endif // POTION_H
