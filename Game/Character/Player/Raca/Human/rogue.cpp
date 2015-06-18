#include "rogue.h"

const int Rogue::rog_strenght = 5;
const int Rogue::rog_intelligence = 8;
const int Rogue::rog_agility = 14;
const int Rogue::rog_strenght_level = 0;
const int Rogue::rog_intelligence_level = 1;
const int Rogue::rog_agility_level = 2;
const int Rogue::rog_bonus = STRENGHT;
std::string Rogue::rogue_img_way = "Character/rogue.png";
std::string Rogue::rogue_img_battle = "Character/rogue.png";

Rogue::Rogue(int new_pos_i, int new_pos_j,
             Direction new_eye_direction = DOWN): Human(new Dagger(1),
                                                  new_pos_i, new_pos_j,
                                                  rogue_img_way,
                                                  rogue_img_battle,
                                                  new_eye_direction)
{
    this->setStrenght(rog_strenght);
    this->setAgility(rog_agility);
    this->setIntelligence(rog_intelligence);
    this->setStrenghtLevel(rog_strenght_level);
    this->setAgilityLevel(rog_agility_level);
    this->setIntelligencetLevel(rog_intelligence_level);
    this->setBonusLevel(rog_bonus);
}

void Rogue::setImgWay(std::string new_img_way)
{
    rogue_img_way = new_img_way;
}

void Rogue::setImgBattle(string new_img_battle)
{
    rogue_img_battle = new_img_battle;
}

Rogue::~Rogue()
{

}

