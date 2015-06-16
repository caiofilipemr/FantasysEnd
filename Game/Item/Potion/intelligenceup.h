#ifndef INTELLIGENCEUP_H
#define INTELLIGENCEUP_H

#include "potion.h"

class IntelligenceUP : public Potion
{
private:
    static std::string int_img_way;
public:
    IntelligenceUP();
    ~IntelligenceUP();
    void doEffect(Player & player);
    static void setImgWay(std::string new_img_way);
};

#endif // INTELLIGENCEUP_H
