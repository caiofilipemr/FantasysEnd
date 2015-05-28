#include "engine.h"

Engine::Engine()
{
    my_player = new Archer(1, 1, DOWN);
    my_map = new Map("mapa.txt", "roguelikeSheet_transparent.png");
    mobs = new Monster*[5];
    mobs[0] = new Stalker(10, 10, 10, 10, 1, 90, 6, 5, 3, 10, 10, "", DOWN);
}

void Engine::update()
{
    if (my_map->hasColision(my_player->getCordenates() + my_player->getDirection())) my_player->update();
    mobs[0]->setStalk(my_player);
    mobs[0]->update();
}

void Engine::setPlayerDirection(Direction new_direction)
{
    my_player->setDirection(new_direction);
}

Cordenates Engine::getPlayerCordenates()
{
    return my_player->getCordenates();
}

Cordenates Engine::getTemp()
{
    return mobs[0]->getCordenates();
}
