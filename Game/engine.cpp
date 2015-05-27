#include "engine.h"

Engine::Engine()
{
    Stalker my_stalker(2, 90, 10, 5, 12, 1, 1, "monster.png", SLEEP);
    mobs[0] = my_stalker;
}
