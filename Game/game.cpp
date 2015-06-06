#include "game.h"
#include "ui_game.h"

using namespace std;

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    this->setMaximumHeight(11 * 32); //Constanstes, passar pra static const int depois
    this->setMinimumHeight(11 * 32);
    this->setMaximumWidth(15 * 32);
    this->setMinimumWidth(15 * 32);
    painter = new QPainter(this);
    my_GUI = new GUIQT(/*painter*/);
    my_engine = new Engine((GUI *)my_GUI);

    clock = new QTimer(this);
    clock->setInterval(1000/60);
    connect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
    clock->start();
    atual_direction = SLEEP;
    my_GUI->setQPainter(painter);
    is_battle = is_inventory = false;
}

Game::~Game()
{
    delete ui;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
       atual_direction = UP;
        break;
    case Qt::Key_Down:
       atual_direction = DOWN;
        break;
    case Qt::Key_Left:
       atual_direction = LEFT;
        break;
    case Qt::Key_Right:
       atual_direction = RIGHT;
        break;
    case Qt::Key_Pause:
        clock->stop();
        break;
    case Qt::Key_Enter:
        clock->start();
        break;
    case Qt::Key_1:
        if (is_battle) {
            try {
                my_engine->battle(ATTACK);
            } catch (Exceptions exc) {
                if (exc == GAME_OVER) {
                    cerr << "GAME OVER\n";
                } else if (exc == CHARACTER_DIE) {
                    clock->start();
                    is_battle = false;
                }
            } catch (const char * err) {
                cerr << err;
            }
        }
        break;
     case Qt::Key_I:
        is_inventory = true;
        //cerr << "Inventory";
        break;
    }
}

void Game::keyReleaseEvent(QKeyEvent * event)
{
    atual_direction = SLEEP;
}

void Game::paintEvent(QPaintEvent *event)
{
    painter->begin(this);
    my_GUI->drawMap();
    if(is_inventory){
      my_GUI->drawInventory();
    }
    painter->end();
}

void Game::myUpdate()
{
    my_engine->setPlayerDirection(atual_direction);
    is_battle = my_engine->isBattle();
    if (is_battle) {
        repaint();
        clock->stop();
    }
    else { my_engine->update(); repaint(); }
    //cerr << "Player- I =" <<my_engine->getPlayerCordenates().i<<" J =" << my_engine->getPlayerCordenates().j<< endl;
    //cerr << "Monster - I =" <<my_engine->getTemp().i<<" J =" << my_engine->getTemp().j<< endl;
}
