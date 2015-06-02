#include "interation.h"

Interation::Interation(std::string new_cmd_name) : cmd_name(new_cmd_name)
{
}


OpenChest::OpenChest(std::string new_cmd_name) : Interation(new_cmd_name)
{

}


AttackStone::AttackStone(std::string new_cmd_name) : Interation(new_cmd_name)
{

}
