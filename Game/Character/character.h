#ifndef CHARACTER_H
#define CHARACTER_H

#include "map.h"

class Inventory;

class Character : public Object {
protected:
    int hp, hp_max, mp, mp_max, guard, damage, speed;
    const int accuracy, dodge, range_damage, critical;
//    Special *special;
//    Condition *condition;
//    Animation *animacao;
    Direction walk_direction, eye_direction;
    int cont;
    bool is_walking, is_dead;
    std::string img_battle;
    static const int limit;

public:
    Character(int new_speed, int new_accuracy,
              int new_dodge, int new_range_damage,
              int new_critical, int new_pos_i,
              int new_pos_j, std::string new_img_way,
              std::string new_img_battle,
              Direction new_eye_direction);
    int attack(Exceptions &exc);
    int attack();
    void setSpecialHp();
    void setSpecialDamage();
    void defense(int attack, Exceptions &exc);
    void addHP(int hp_plus);
    void addMP(int mp_plus);
    int getHP();
    int getHPMax();
    int getMP();
    int getMPMax();
    int getDamage();
    int getGuard();
    virtual void setDirection(Direction new_direction);
    void setEyeDirection(Direction new_eye_direction);
    Direction getDirection();
    Direction getEyeDirection();
    virtual void walk() = 0;
    virtual void update(Map * my_map);
    virtual int getCont();
    virtual bool getIsWalking();
    virtual void die(Map * my_map) = 0;
    std::string getImgBatlle();
    static int getLimit();
    bool isDead();
};

#endif // CHARACTER_H
