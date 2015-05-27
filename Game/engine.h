#ifndef ENGINE_H
#define ENGINE_H

#include "map.h"
#include "Character/Monster/stalker.h"
#include "Character/Monster/sleeper.h"
#include "Character/Monster/walker.h"
#include "Character/Player/player.h"
#include "stone.h"
#include "chest.h"
#include "globalfunctions.h"
#include "Enums.h"

class Engine
{
private:
    Map my_map;
    Monster mobs[5];
    Player my_player;
    Stone * my_stones;
    Chest * my_chests;
public:
    Engine();
};

#endif // ENGINE_H
