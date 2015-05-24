#include "level.h"

const int Level::xp_max[4] = {100, 300, 500, 700};

void Level::setStrenghtLevel(int new_strenght_level)
{
    strenght_level = new_strenght_level;
}

void Level::setAgilityLevel(int new_agility_level)
{
    agility_level = new_agility_level;
}

void Level::setIntelligencetLevel(int new_intelligence_level)
{
    intelligence_level = new_intelligence_level;
}

void Level::setBonusLevel(int new_bonus_level)
{
    bonus_level = new_bonus_level;
}

Level::Level() : level(1), xp(0)
{
}

Level::~Level()
{

}

void Level::up()
{
    addStrenght(strenght_level);
    addAgility(agility_level);
    addIntelligence(intelligence_level);
    if (level % 2){
        switch (bonus_level) {
        case STRENGHT:
            addStrenght(1);
            break;
        case AGILITY:
            addStrenght(1);
            break;
        case INTELLIGENCE:
            addStrenght(1);
            break;
        }
    }
}

int Level::getLevel()
{
    return level;
}

int Level::getStrenght()
{
    return strenght;
}

int Level::getAgility()
{
    return agility;
}

int Level::getIntelligence()
{
    return intelligence;
}

void Level::addXP(int xp_plus)
{
    if (level == 5) return;
    if ((xp + xp_plus) > xp_max[level-1]) {
        xp_plus = xp_plus + xp - xp_max[level-1];
        xp = xp_max[level-1];
        level++;
        up();
        addXP(xp_plus);
    }
    else
        xp += xp_plus;
}
