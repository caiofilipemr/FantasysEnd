#include "engine.h"

Engine::Engine()
{
    my_player = new Archer(1, 1, DOWN);
    my_map = new Map("mapa.txt", "roguelikeSheet_transparent.png");
}

void Engine::update()
{
    if (my_map->hasColision(my_player->getCordenates() + my_player->getDirection())) my_player->update();
}

void Engine::setPlayerDirection(Direction new_direction)
{
    my_player->setDirection(new_direction);
}

Cordenates Engine::getPlayerCordenates()
{
    return my_player->getCordenates();
}
