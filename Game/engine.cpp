#include "engine.h"
const int Engine::number_of_mobs = 3;

Engine::Engine(GUI *new_engine_GUI) : engine_GUI(new_engine_GUI)
{
    CellArray::instance();
    my_map = new Map("Maps/mapa.txt", "Images/roguelikeSheet_transparent.png", &mobs);
    CellArray::instance()->setCell(my_map->getCordenates().i, my_map->getCordenates().j, my_map->getColision());

    engine_GUI->setDrawMap(my_map);
    engine_GUI->setDrawMobs(&mobs);
    my_battle = NULL;
    open_chest = NULL;
    is_battle = false;
    RandItens::randItensMap();
    my_player = new Barbaro(30,30,DOWN);
}

Engine::~Engine()
{
    delete my_map;
    delete my_player;
    delete battle_mob;
    delete my_battle;
}

void Engine::update()
{
    try {
        my_player->update(my_map);
        for (size_t i = 0; i < mobs.size(); i++) {
            if (!is_battle) {
                mobs[i]->setCanGo(my_map->getCanGo(mobs[i]->getCordenates()));
                mobs[i]->update(my_map);
            }
        }
    } catch (const char * e) { cerr << e << endl; }
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
    if (mobs.size())
        return mobs[0]->getCordenates();
    return Cordenates(0,0);
}

bool Engine::isBattle()
{
    is_battle = false;
    //Arrumar uma solução MELHOR!!!
    if (/*!mobs[0]->getIsWalking()*/!Monster::getMonsterIsWalking()) {
        for (size_t i = 0; i < mobs.size(); i++) {
            if (mobs[i]) {
                if ((mobs[i]->getCordenates() + UP) == my_player->getCordenates()) {
                    battle_mob = mobs[i];
                    mobs[i]->setEyeDirection(UP);
                    is_battle = true;
                }
                else if ((mobs[i]->getCordenates() + DOWN) == my_player->getCordenates()) {
                    battle_mob = mobs[i];
                    mobs[i]->setEyeDirection(DOWN);
                    is_battle = true;
                }
                else if ((mobs[i]->getCordenates() + RIGHT) == my_player->getCordenates()) {
                    battle_mob = mobs[i];
                    mobs[i]->setEyeDirection(RIGHT);
                    is_battle = true;
                }
                else if ((mobs[i]->getCordenates() + LEFT) == my_player->getCordenates()){
                    battle_mob = mobs[i];
                    mobs[i]->setEyeDirection(LEFT);
                    is_battle = true;
                }
                if (is_battle) {
                    my_battle = new Battle(my_player, mobs[i]);
                    is_player_turn = true;
                    return is_battle;
                }
            }
        }
    }
    return is_battle;
}

bool Engine::isPlayerTurn()
{
    if (!is_battle) throw "IS NOT BATTLE!";
    return is_player_turn;
}

int Engine::battle(BattleOptions op, Exceptions &exc_atk, Exceptions &exc_def)
{
    if (is_battle) {
        int atk;
        is_player_turn = !is_player_turn;
        switch (op) {
        case ATTACK:
            atk = my_battle->attack(exc_atk, exc_def);
            try {
                if (exc_def == CHARACTER_DIE){
                    Character *dead_character = my_battle->getDefenserFighter();
                    dead_character->die(my_map);
                    size_t i;
                    for (i = 0; i < mobs.size() && mobs[i] != (dead_character); i++);
                    if (i == mobs.size()) throw "Error!";
                    my_player->addXP(mobs[i]->getDropXP());
                    delete mobs[i];
                    mobs.erase(mobs.begin() + i);
                    is_battle = false;
                    delete my_battle;
                    my_battle = NULL;
                }
            } catch (Exceptions e) {
                if (e == GAME_OVER) {
                    is_battle = false;
                    gameOver();
                }
                exc_def = e;
            }
            return atk;
            break;

        case MAGIC_SPECIAL:

            break;

        case ITEM:

            break;
 //criar uma static em Monster para saber se o isWalking --SAVIO
        case RUN:

            break;

        default:
            break;
        }
    }
    return 0;
}

void Engine::gameOver()
{

}

bool Engine::isWalking() //talvez temp, estou com sono, nao sei kk
{
    return (my_player->getIsWalking());
}

std::vector<string> Engine::getCommands(int index)
{
    std::vector <Commands *> cmds = my_player->getCommands(index);
    std::vector<string> cmd_name;
    for (size_t i = 0; i < cmds.size(); i++) cmd_name.push_back(cmds[i]->getCmdName());
    return cmd_name;
}

void Engine::doCommand(int row_item, int row_command)
{
    //try {
        my_player->getCommands(row_item)[row_command]->doThis((*my_player));
    //} catch (const char *err) {
    //    cerr << err;
    //}
}

void Engine::interation()
{
    Cordenates player_eye = my_player->getCordenates() + my_player->getEyeDirection();
    Object * object = my_map->getObjectMap(player_eye);
    try {
        if (object) object->interate(my_player);
    } catch(Exceptions e){
        if (e == BROKEN_STONE) {
            my_map->removeAColision(player_eye);
            my_map->removeObjects(player_eye);
            player_eye = object->getCordenates();
            Object * broken_stone = new Object(player_eye.i,player_eye.j,Stone::getImgBrokenStone());
            my_map->addObjects(broken_stone,player_eye);
        }
        else if (e == OPEN_CHEST) {
            open_chest = (Chest*)object;
            throw;
        } else throw;
    }
}

void Engine::setPlayer(PlayerClass pc)
{
    switch (pc) {
    case ARCHER:
        my_player = new Archer(40, 60, DOWN);
        break;
    case BARBARO:
        my_player = new Barbaro(40, 60, DOWN);
        break;
    case TROLL:
        my_player = new Troll(40, 60, DOWN);
        break;
    case URUKHAY:
        my_player = new Urukhay(40, 60, DOWN);
        break;
    case ROGUE:
        my_player = new Rogue(40, 60, DOWN);
        break;
    case MAGE:
        my_player = new Mage(40, 60, DOWN);
        break;
    default:
        throw "This player class not exist!";
        break;

    }
    engine_GUI->setDrawPlayer(my_player);
    mobs.push_back(new Sleeper(5, 1, 29, 58, "Monster/monster_black.png","Battle/0 [updated].png", DOWN));
    mobs.push_back(new Sleeper(4, 1, 33, 14, "Monster/monster_red.png","Battle/0 [updated].png", DOWN));
    mobs.push_back(new Sleeper(1, 1, 58, 49, "Monster/monster_grey.png","Battle/0 [updated].png", DOWN));
    mobs.push_back(new Walker(2, 1, 51, 21, "Monster/monster_orange.png","Battle/0 [updated].png", DOWN));
    mobs.push_back(new Walker(1, 1, 19, 70, "Monster/monster_grey.png","Battle/0 [updated].png", DOWN));
    mobs.push_back(new Walker(3, 1, 45, 72, "Monster/monster_green.png","Battle/0 [updated].png", DOWN));
    mobs.push_back(new Stalker(2, 1, 15, 12, "Monster/monster_orange.png","Battle/0 [updated].png", DOWN));
    mobs.push_back(new Stalker(3, 1, 56, 74, "Monster/monster_green.png","Battle/0 [updated].png", DOWN));
    mobs.push_back(new Stalker(1, 1, 42, 35, "Monster/monster_grey.png","Battle/0 [updated].png", DOWN));
    for (size_t i = 0; i < mobs.size(); i++) mobs[i]->setStalk(my_player);

    my_map->distributeItensMap();
}

void Engine::setSpecialX()
{
    my_player->setSpecialHp();
}

void Engine::setSpecialZ()
{
    my_player->setSpecialDamage();
}

Chest *Engine::getOpenChest()
{
    return open_chest;
}

void Engine::closeChest()
{
    open_chest = NULL;
}

void Engine::takeItemChest(int i)
{
    if (i < 0 || i >= open_chest->getSize()) throw "Bad index";
    my_player->addItemInventory(open_chest->removeItem(i)); //Remove o item do baú e adciona-o ao inventário do Player
}

