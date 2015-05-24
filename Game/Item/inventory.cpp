#include "inventory.h"

const int Inventory::max_item = 15;
const int Inventory::mod_weight = 5;

Inventory::Inventory()
{
    item = new Item *[max_item];
    index = weight = 0;
}

void Inventory::setMaxWeight(int strenght)
{
    weight_max = mod_weight * strenght;
}

bool Inventory::addItem(Item * new_item)
{
    if (weight + new_item->getWeight() <= weight_max && index < max_item){
        item[index++] = new_item;
        weight += new_item->getWeight();
        return true;
    }
    return false;
}

Item *Inventory::removeItem(int item_index)
{
    if (item_index < index) throw "Out of Range! (INVENTORY)";
    Item * temp_item = item[item_index];
    for (int i = item_index; i < index; i++)
        item[i] = item[i+1];
    index--;
    return temp_item;
}

int Inventory::getMaxWeight()
{
    return weight_max;
}

int Inventory::getWeight()
{
    return weight;
}

bool Inventory::canCarry(Item can_carry_item)
{
    return ((can_carry_item.getWeight() + weight) <= weight_max);
}
