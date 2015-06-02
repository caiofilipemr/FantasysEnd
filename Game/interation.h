#ifndef INTERATION_H
#define INTERATION_H

#include "object.h"

class Interation
{
protected:
    const std::string cmd_name;
public:
    Interation(std::string new_cmd_name);
};

class OpenChest : public Interation
{
public:
    OpenChest(std::string new_cmd_name);
};

class AttackStone : public Interation
{
public:
    AttackStone(std::string new_cmd_name);
};


#endif // INTERATION_H
