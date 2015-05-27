#ifndef CHEST_H
#define CHEST_H

#include "object.h"
#include <vector>

class Chest : public Object
{
private:
    std::vector<Item*> itens_list;
    void randItem(int rand);
public:
    Chest(int new_pos_i, int new_pos_j, std::string new_img_way);
    ~Chest();
    Item *getItem();
    Item *removeItem(int item_index);
};

#endif // CHEST_H
