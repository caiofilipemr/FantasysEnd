#ifndef STRENGTUP_H
#define STRENGTUP_H

#include "potion.h"

class StrengtUP : private Potion
{
private:
    static std::string strengt_img_way;
public:
    StrengtUP();
    ~StrengtUP();
    void doEffect(Player & player);
    static void setImgWay(std::string new_img_way);
};

#endif // STRENGTUP_H
