#include "inventory.h"

const int Inventory::max_item = 15;
const int Inventory::mod_weight = 5;

Inventory::Inventory()
{
    index = weight = 0;
}

void Inventory::setMaxWeight(int strenght)
{
    weight_max = mod_weight * strenght;
}

bool Inventory::addItem(Item * new_item)
{
    if (weight + new_item->getWeight() <= weight_max && index < max_item){
        itens_list.push_back(new_item);
        weight += new_item->getWeight();
        index++;
        return true;
    }
    return false;
}

bool Inventory::isItem(int new_index)
{
    return new_index < index;
}

Item *Inventory::removeItem(int item_index)
{
    if (item_index >= index) throw "Out of Range! (INVENTORY)";
    Item * temp_item = itens_list[item_index];
    weight -= temp_item->getWeight();
    itens_list.erase(itens_list.begin() + item_index);
    index--;
    return temp_item;
}

Item *Inventory::removeItem(Item *remove_item)
{
    int i;
    for (i = 0; i < index && remove_item != itens_list[i]; i++);
    if (i == index) throw "Item not found!";
    return removeItem(i);
}

Item *Inventory::getItem(int item_index)
{
    if(int(itens_list.size()) - 1 < item_index) throw "Item not found";
    return itens_list[item_index];
}

int Inventory::getMaxWeight()
{
    return weight_max;
}

int Inventory::getWeight()
{
    return weight;
}

int Inventory::size()
{
    return index;
}

bool Inventory::canCarry(Item * can_carry_item)
{
    return ((can_carry_item->getWeight() + weight) <= weight_max);
}
