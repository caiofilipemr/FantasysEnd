#ifndef STALKER_H
#define STALKER_H

#include "Character/Monster/walker.h"
#include "globalfunctions.h"
#include "macros.h"

class Stalker : public Walker
{
private:
    void stalk(int end_i, int end_j);
public:
    Stalker(int new_speed, int new_accuracy,
            int new_dodge, int new_range_damage,
            int new_critical, int new_pos_i,
            int new_pos_j, std::string new_img_way,
            Direction new_eye_direction);
    void walkOrStalk(Object *player);
};

#endif // STALKER_H
