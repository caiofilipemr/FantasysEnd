#ifndef ENGINE_H
#define ENGINE_H

#include "map.h"
#include "Character/Monster/stalker.h"
#include "Character/Monster/sleeper.h"
#include "Character/Monster/walker.h"
#include "Character/Player/player.h"
<<<<<<< HEAD
#include "stone.h"
#include "chest.h"
#include "globalfunctions.h"
#include "Enums.h"
=======
#include "globalfunctions.h"
>>>>>>> 81ea6d2bef33c9d41b8d698f19ab5384d4ab9560

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
