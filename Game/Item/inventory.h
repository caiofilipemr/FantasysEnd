#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item/item.h"
#include "globalfunctions.h"


class Inventory
{
private:
    static const int max_item, mod_weight;
    int weight_max, index, weight;
    std::vector<Item*> itens_list;

public:
    Inventory();
    void setMaxWeight(int strenght);
    bool addItem(Item * new_item);
    Item *removeItem(int item_index);
    Item *removeItem(Item * remove_item);
    Item * getItem(int item_index);
    int getMaxWeight();
    int getWeight();
    bool canCarry(Item * can_carry_item);
};

#endif // INVENTORY_H
