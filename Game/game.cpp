#include "game.h"
#include "ui_game.h"


using namespace std;

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    //Iniciando UI!!!
    ui->setupUi(this);

    //Tamanho da window
    static const int w = 15*32, h = 11*32;

    //Setando tamanho máximo
    this->setMaximumHeight(h); this->setMinimumHeight(h);
    this->setMaximumWidth(w); this->setMinimumWidth(w);

    //Iniciando o QPainter, GUIQT, Engine e o QTimer!!!
    painter = new QPainter(this); my_GUI = new GUIQT(); my_GUI->setQPainter(painter); my_engine = new Engine((GUI *)my_GUI); clock = new QTimer(this);

    //Iniciando o QTimer em 60 FPS, conectando o sinal TIMEOUT() do QTimer com a função SLOT mainMenu() e startando ele!!!
    clock->setInterval(1000/60); connect(clock, SIGNAL(timeout()), this, SLOT(mainMenu())); clock->start();

    //Instanciando os objetos de SOM!!!
    world_music = new QMediaPlayer; instant_sfx = new QMediaPlayer; battle_music = new QMediaPlayer;

    //Instanciando uma playlist para poder loopar as músicas de fundo, adicionando o caminho para a música de fundo principal do jogo na playlist, setando o modo loop e adicionando a playlist ao QMediaPlayer!!
    QMediaPlaylist *temp_playlist = new QMediaPlaylist; temp_playlist->addMedia(QUrl::fromLocalFile(QFileInfo("Music/Stairway to Heaven - Symphonic Led Zeppelin.mp3").absoluteFilePath()));
    temp_playlist->setPlaybackMode(QMediaPlaylist::Loop); world_music->setPlaylist(temp_playlist);

    //Instanciando uma playlist para poder loopar as músicas de fundo, adicionando o caminho para a música de fundo da batalha na playlist, setando o modo loop e adicionando a playlist ao QMediaPlayer!!
    temp_playlist = new QMediaPlaylist; temp_playlist->addMedia(QUrl::fromLocalFile(QFileInfo("Battle/The Last Encounter (90s RPG Version) Full Loop.wav").absoluteFilePath()));
    temp_playlist->setPlaybackMode(QMediaPlaylist::Loop); battle_music->setPlaylist(temp_playlist);

    //Startando a música de fundo principal!!
    world_music->play();

    //Iniciando os valores em falso ou 0!!!
    player_key = Qt::Key_0; is_battle = is_inventory = interactive_button = is_transiction = tutorial_buffer = false;
    x_mouse = y_mouse = trans_m_b_cont = 0;

    //Iniciando as opções de tela com seus devidos valores iniciais!!!
    current_painter_option = P_MAIN_MENU; current_transiction = NONE; current_over = O_NONE;
}

Game::~Game()
{
    if (world_music->playlist()) delete world_music->playlist();
    if (battle_music->playlist()) delete battle_music->playlist();
    if (world_music) delete world_music;
    if (instant_sfx) delete instant_sfx;
    if (battle_music) delete battle_music;
    delete ui;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (current_over == PAUSE) {//Se estiver pausado nenhuma tecla apertada pode fazer efeito a não ser a própria tecla de PAUSE, no caso DESPAUSA o jogo!!!
        if  (event->key() == Qt::Key_Q) {
            clock->start();
            current_over = O_NONE;
            repaint();
        }
        return;
    }
    switch (event->key()) {
    case Qt::Key_W:
        if (!directions[UP]) {
            movement_stack.push_back(UP);
            directions[UP] = true;
        }
        break;
    case Qt::Key_S:
        if (!directions[DOWN]) {
            movement_stack.push_back(DOWN);
            directions[DOWN] = true;
        }
        break;
    case Qt::Key_A:
        if (!directions[LEFT]) {
            movement_stack.push_back(LEFT);
            directions[LEFT] = true;
        }
        break;
    case Qt::Key_D:
        if (!directions[RIGHT]) {
            movement_stack.push_back(RIGHT);
            directions[RIGHT] = true;
        }
        break;
    case Qt::Key_Q:
        if (current_painter_option < P_GAME_OVER) {
            clock->stop();
            current_over = PAUSE;
            repaint();
        }
        break;
    case Qt::Key_Tab: //Abre a STATUS BAR!!!
        if (current_transiction == STATUS_BAR) current_transiction = NONE;
        else if (current_painter_option == P_MAP && current_transiction == NONE) {
            current_transiction = STATUS_BAR;
            my_GUI->resetStatusBar();
            repaint();
        }
        break;
     case Qt::Key_E: //Abre o INVENTARIO!!!
        if (current_painter_option == P_MAP) {
            if(current_transiction == INVENTORY) {
                my_engine->closeChest();
                my_GUI->clearInventory();
                disconnect(clock, SIGNAL(timeout()), this, SLOT(myInventory()));
                interactive_button = false;
                connect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
                current_transiction = NONE;
            }
            else {
                disconnect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
                connect(clock, SIGNAL(timeout()), this, SLOT(myInventory()));
                current_transiction = INVENTORY;
                repaint();
            }
        }
        break;
    case Qt::Key_Space:
        interactive_button = true;
        break;
    }

    //CHEATS!!
    if(event->key() == Qt::Key_Z && event->modifiers() == Qt::ShiftModifier) {
        my_engine->setSpecialZ(); //damage + 100
    }
    if(event->key() == Qt::Key_X && event->modifiers() == Qt::ShiftModifier) {
        my_engine->setSpecialX(); //hp = hp_max
    }
}

void Game::keyReleaseEvent(QKeyEvent * event)
{
    if (current_painter_option == P_MAP) {
        Direction dir;
        switch (event->key()) {
        case Qt::Key_W:
            dir = UP;
            break;
        case Qt::Key_S:
            dir = DOWN;
            break;
        case Qt::Key_A:
            dir = LEFT;
            break;
        case Qt::Key_D:
            dir = RIGHT;
            break;
        default:
            return;
        }
        int i, s = movement_stack.size();
        for (i = 0; i < s && dir != movement_stack[i]; i++);
        if (i < s) {
            movement_stack.erase(movement_stack.begin() + i);
            directions[dir] = false;
        }
    }
}

void Game::paintEvent(QPaintEvent *)
{
    painter->begin(this);

    switch (current_painter_option) {
    case P_MAP:
        my_GUI->drawMap();
        break;
    case P_BATTLE:
        my_GUI->drawBattle();
        break;
    case P_GAME_OVER:
        my_GUI->drawGameOver();
        break;
    case P_MAIN_MENU:
        my_GUI->drawMainMenu();
        if (!tutorial_buffer) my_GUI->drawTutorial();//mostra o tutorial!!!
        break;
    default:
        break;
    }

    switch (current_transiction) {
    case NONE:
        break;
    case OPEN:
        my_GUI->drawTransictionMapBattle(trans_m_b_cont);
        break;
    case CLOSE:
        my_GUI->drawTransictionMapBattle(trans_m_b_cont);
        break;
    case INVENTORY:
        my_GUI->drawInventory();
        break;
    case STATUS_BAR:
        my_GUI->drawStatusBar();
        break;
    default:
        break;
    }

    switch (current_over) {
    case PAUSE:
        my_GUI->drawPauseScreen();
        break;
    default:
        break;
    }

   painter->end();
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if (current_transiction == INVENTORY && current_over != PAUSE) {
        this->x_mouse = event->x();
        this->y_mouse = event->y();
        if(event->button() == Qt::RightButton) {
            my_GUI->setCursor(x_mouse, y_mouse, BUTTON_RIGHT);
            try {
                int i = my_GUI->takeItemChest();
                my_engine->takeItemChest(i);
                repaint();
            } catch (const char * err) { //Tá zoado, verificar depois, pois o catch só serve como um "else"
                if (my_GUI->currentInventorySelected() == IS_INVENTORY) {
                    my_GUI->setCommands(my_engine->getCommands(my_GUI->rowItemChest()));
                }
            }
        } else {
            my_GUI->setCursor(x_mouse, y_mouse, BUTTON_LEFT);
            if (my_GUI->isRowCommand()) {
                int row_item = my_GUI->rowItemChest(), row_command = my_GUI->rowCommand();
                my_GUI->clearCursor();
                my_engine->doCommand(row_item, row_command);
            }
        }
        repaint();
    }
}

void Game::mainMenu()
{    
    if (!my_GUI->isMMDelay()) {
        if (interactive_button) {
            if (!tutorial_buffer) {
                tutorial_buffer = true;
                interactive_button = false;
                movement_stack.clear();
                directions.clear();
                repaint();
                return;
            }
            my_engine->setPlayer(my_GUI->getSelectedOptionMM());
            disconnect(clock, SIGNAL(timeout()), this, SLOT(mainMenu()));
            connect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
            current_painter_option = P_MAP;
        } else {
            if (!movement_stack.empty() && tutorial_buffer) {
                if (my_GUI->moveCursorMM(movement_stack.back())) {
                    instant_sfx->setMedia(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(Battle::cursor_change_sound)).absoluteFilePath()));
                    instant_sfx->play();
                    my_GUI->MMDelayCont();
                }
                movement_stack.clear();
                directions.clear();
                repaint();
            }
        }
    }
    else {
        my_GUI->MMDelayCont();
        repaint();
    }
}

void Game::myUpdate()
{
    is_battle = my_engine->isBattle();
    if (is_battle && !my_engine->isWalking()) {
        my_GUI->resetSelectedOption();
        movement_stack.clear();
        directions.clear();
        clock->setInterval(1000/200);
        disconnect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
        connect(clock, SIGNAL(timeout()), this, SLOT(transictionMapBattle()));
        trans_m_b_cont++;
        current_transiction = CLOSE;
        battle_music->setVolume(100);
        battle_music->play();
        world_music->pause();
    }
    else {
        Direction atual_direction = movement_stack.empty() ? SLEEP : movement_stack.back();
        my_engine->setPlayerDirection(atual_direction);
        my_engine->update();
        is_battle = false;
        repaint();
    }
    if (interactive_button && current_painter_option == P_MAP) {
        try {
            try {
                my_engine->interation();
            } catch(Exceptions e){
                if (e == OPEN_CHEST) {
                    my_GUI->setChest(my_engine->getOpenChest());
                    disconnect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
                    connect(clock, SIGNAL(timeout()), this, SLOT(myInventory()));
                    current_transiction = INVENTORY;
                    repaint();
                }
            }
        } catch (Exceptions e) { cerr << "Erro"; };
        interactive_button = false;
    }
}

void Game::myBattle()
{
    Exceptions exc_atk, exc_def = HIT;
    BattleOptions selected_option;

    if (!(my_GUI->isBattleDelay())) {
        if(!my_engine->isPlayerTurn()) {
            interactive_button = true;
            selected_option = ATTACK;
        } else {
            selected_option = my_GUI->getSelectedOptionBattle();
        }

        if (interactive_button) {
            int player_turn = my_engine->isPlayerTurn();
            int ret = my_engine->battle(selected_option, exc_atk, exc_def);

                switch (exc_atk) {
                case HIT:
                    instant_sfx->setMedia(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(Battle::options_sounds[my_GUI->getSelectedOptionBattle()])).absoluteFilePath()));
                    instant_sfx->play();
                    my_GUI->battleDelayCont();
                    my_GUI->setBattleText(exc_atk, QString::number(ret), player_turn);
                    break;
                case CRITICAL:
                    instant_sfx->setMedia(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(Battle::options_sounds[my_GUI->getSelectedOptionBattle()])).absoluteFilePath()));
                    instant_sfx->play();
                    my_GUI->battleDelayCont();
                    my_GUI->setBattleText(exc_atk, player_turn);
                    my_GUI->setBattleText(exc_atk, QString::number(ret), player_turn);
                    break;
                case DODGE:
                    my_GUI->setBattleText(exc_atk, player_turn);
                    instant_sfx->setMedia(QUrl::fromLocalFile(QFileInfo("Music/swing3.wav").absoluteFilePath()));
                    instant_sfx->play();
                    break;
                case MISS:
                    my_GUI->setBattleText(exc_atk, !player_turn);
                    instant_sfx->setMedia(QUrl::fromLocalFile(QFileInfo("Music/swing3.wav").absoluteFilePath()));
                    instant_sfx->play();
                    break;
                default:
                    break;
                }
                switch (exc_def) {
                case HIT:
                    break;
                case GAME_OVER:
                    instant_sfx->setMedia(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(Battle::options_sounds[my_GUI->getSelectedOptionBattle()])).absoluteFilePath()));
                    instant_sfx->play();
                    disconnect(clock, SIGNAL(timeout()), this, SLOT(myBattle()));
                    connect(clock, SIGNAL(timeout()), this, SLOT(transictionBattleGO()));
                    current_transiction = CLOSE;
                    break;
                case CHARACTER_DIE:
                    instant_sfx->setMedia(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(Battle::options_sounds[my_GUI->getSelectedOptionBattle()])).absoluteFilePath()));
                    instant_sfx->play();
                    disconnect(clock, SIGNAL(timeout()), this, SLOT(myBattle()));
                    connect(clock, SIGNAL(timeout()), this, SLOT(transictionBattleMap()));
                    current_transiction = CLOSE;
                    break;
                default:
                    break;
                }
                my_GUI->battleDelayCont();
                interactive_button = false;

        } else if (!movement_stack.empty()) {
            if (my_GUI->moveCursorBattle(movement_stack.back())) {
                instant_sfx->setMedia(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(Battle::cursor_change_sound)).absoluteFilePath()));
                instant_sfx->play();
            }
        }

    } else {
        my_GUI->battleDelayCont();
    }
    movement_stack.clear();
    directions.clear();
    repaint();
}

void Game::myInventory()
{

}

void Game::transictionMapBattle()
{
    if (current_transiction == CLOSE) {
        repaint();
        trans_m_b_cont++;
        if (trans_m_b_cont > 240) {
            current_painter_option = P_BATTLE;
            current_transiction = OPEN;
        }
    } else if (trans_m_b_cont > 0) {
        repaint();
        trans_m_b_cont--;
    } else {
        disconnect(clock, SIGNAL(timeout()), this, SLOT(transictionMapBattle()));
        connect(clock, SIGNAL(timeout()), this, SLOT(myBattle()));
        clock->setInterval(1000/7);
        movement_stack.clear();
        directions.clear();
        current_transiction = NONE;
        interactive_button = false;
    }
}

void Game::transictionBattleMap()
{
    if (my_GUI->isBattleDelay()) {
        my_GUI->battleDelayCont();
        repaint();
        if (!my_GUI->isBattleDelay()) clock->setInterval(1000/200);
    }
    else {
        if (current_transiction == CLOSE) { //Arrumar constante depois, esse 240 é a largura da tela dividida por 2
            repaint();
            trans_m_b_cont++;
            if (trans_m_b_cont > 240) {
                current_painter_option = P_MAP;
                current_transiction = OPEN;
            }
        } else if (trans_m_b_cont > 0) {
            repaint();
            trans_m_b_cont--;
        } else {
            disconnect(clock, SIGNAL(timeout()), this, SLOT(transictionBattleMap()));
            connect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
            clock->setInterval(1000/60);
            current_transiction = NONE;
            world_music->play();
            battle_music->stop();
            repaint();
        }
    }
}

void Game::transictionBattleGO()
{
    if (my_GUI->isBattleDelay()) {
        my_GUI->battleDelayCont();
        repaint();
        if (!my_GUI->isBattleDelay()) clock->setInterval(1000/200);
    }
    else {
        if (current_transiction == CLOSE) { //Arrumar constante depois, esse 240 é a largura da tela dividida por 2
            repaint();
            trans_m_b_cont++;
            if (trans_m_b_cont > 240) {
                current_painter_option = P_GAME_OVER;
                current_transiction = OPEN;
            }
        } else if (trans_m_b_cont > 0) {
            repaint();
            trans_m_b_cont--;
        } else {
            disconnect(clock, SIGNAL(timeout()), this, SLOT(transictionBattleGO()));
            clock->stop();
            current_painter_option = P_GAME_OVER;
            current_transiction = NONE;
            battle_music->stop();
            world_music->stop();
            world_music->play();
            repaint();
        }
    }
}
