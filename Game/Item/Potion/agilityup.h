#ifndef AGILITYUP_H
#define AGILITYUP_H

#include "potion.h"

class AgilityUP : public Potion
{
private:
    static std::string agility_img_way;
public:
    AgilityUP();
    ~AgilityUP();
    void doEffect(Player & player);
    static void setImgWay(std::string new_img_way);
};

#endif // AGILITYUP_H
