#include "game.h"
#include "ui_game.h"

using namespace std;

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    clock = new QTimer(this);
    clock->setInterval(16);
    connect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
    clock->start();
    atual_direction = SLEEP;
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
    }
}

void Game::keyReleaseEvent(QKeyEvent * event)
{
    atual_direction = SLEEP;
}

void Game::myUpdate()
{
    my_engine.setPlayerDirection(atual_direction);
    if (my_engine.isBattle()) {
        clock->stop();
        cerr << "BATALHA MODAFOCA!\n";
    }
    else my_engine.update();
    cerr << "Player- I =" <<my_engine.getPlayerCordenates().i<<" J =" << my_engine.getPlayerCordenates().j<< endl;
    cerr << "Monster - I =" <<my_engine.getTemp().i<<" J =" << my_engine.getTemp().j<< endl;
}
