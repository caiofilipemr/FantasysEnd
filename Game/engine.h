#ifndef ENGINE_H
#define ENGINE_H

#include "map.h"
#include "Character/Monster/stalker.h"
#include "Character/Monster/sleeper.h"
#include "Character/Player/Raca/Elf/archer.h"
#include "stone.h"
#include "chest.h"
#include "globalfunctions.h"
#include "Enums.h"
#include "globalfunctions.h"
#include "cellarray.h"
//alt
class Engine
{
private:
    Map *my_map;
    Monster **mobs;
    Player *my_player;
    Stone * my_stones;
    Chest * my_chests;
    //bool * aux_can_go;
public:
    Engine();
    void update();
    void setPlayerDirection(Direction new_direction);
    Cordenates getPlayerCordenates();
    Cordenates getTemp();
};

#endif // ENGINE_H
