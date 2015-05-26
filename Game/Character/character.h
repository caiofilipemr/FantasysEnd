#ifndef CHARACTER_H
#define CHARACTER_H

#include "iostream"
#include "object.h"
#include "Enums.h"
#include "globalfunctions.h"

class Character : public Object {
private:

protected:
    int hp, hp_max, mp, mp_max, guard, damage, speed;
    const int accuracy, dodge, range_damage, critical;
    Special *special;
    Condition *condition;
    Animation *animacao;
    Direction walk_direction, eye_direction;
    int cont;
    bool is_walking;
    static const int limit;

    virtual void setHP() = 0;
    virtual void setMP() = 0;
    virtual void setGuard() = 0;
    virtual void setDamage() = 0;
public:
    Character(int new_speed, int new_accuracy,
              int new_dodge, int new_range_damage,
              int new_critical, int new_pos_i,
              int new_pos_j, std::string new_img_way,
              Direction new_eye_direction);
    int attack();
    void defense(int attack);
    void addHP(int hp_plus);
    void addMP(int mp_plus);
    int getHP();
    int getMP();
    int getGuard();
    void setDirection(Direction new_direction);
    virtual void walk() = 0;
    void update();
    int getCont();
    bool getIsWalking();
};

#endif // CHARACTER_H
