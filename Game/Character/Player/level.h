#ifndef LEVEL_H
#define LEVEL_H

#include "Enums.h"


class Level
{
protected:
    static const int xp_max[4];

    int strenght, agility, intelligence;
    int level, strenght_level, agility_level, intelligence_level, bonus_level, xp;

    void setStrenghtLevel(int new_strenght_level);
    void setAgilityLevel(int new_agility_level);
    void setIntelligencetLevel(int new_intelligence_level);
    void setBonusLevel(int new_bonus_level);
    void up();

public:
    Level();
    ~Level();
    int getLevel();
    int getStrenght();
    int getAgility();
    int getIntelligence();
    void addXP(int xp_plus);

    virtual void addStrenght(int strenght_plus) = 0;
    virtual void addAgility(int agility_plus) = 0;
    virtual void addIntelligence(int intelligence_plus) = 0;
};

#endif // LEVEL_H
