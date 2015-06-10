#include "game.h"
#include "ui_game.h"


using namespace std;

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    x_mouse = y_mouse = 0;

    ui->setupUi(this);
    static const int w = 15*32, h = 11*32;
    this->setMaximumHeight(h);
    this->setMinimumHeight(h);
    this->setMaximumWidth(w);
    this->setMinimumWidth(w);
    painter = new QPainter(this);
    my_GUI = new GUIQT();
    my_engine = new Engine((GUI *)my_GUI);

    clock = new QTimer(this);
    clock->setInterval(1000/60);
    connect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
    clock->start();
    atual_direction = SLEEP;
    my_GUI->setQPainter(painter);
    is_battle = game_over = is_inventory = interactive_button = false;
    mp = new QMediaPlayer;
}

Game::~Game()
{
    if (mp) delete mp;
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
     case Qt::Key_I:
        if(is_inventory) {
            is_inventory = false;
            clock->start();
        }
        else {
            is_inventory = true;
            clock->stop();
            repaint();
        }
        break;
    case Qt::Key_Space:
        interactive_button = true;
        break;
    }
}

void Game::keyReleaseEvent(QKeyEvent * event)
{
    if (!is_battle) atual_direction = SLEEP;
}

void Game::paintEvent(QPaintEvent *event)
{
    painter->begin(this);
    /*if (!is_battle)*/ my_GUI->drawMap();
    if (game_over)
        my_GUI->drawGameOver();
    if(is_inventory){
      my_GUI->drawInventory();
    }
    if (is_battle) my_GUI->drawBattle();
    painter->end();
}

void Game::mousePressEvent(QMouseEvent *event)
{
    this->x_mouse = event->x();
    this->y_mouse = event->y();
    my_GUI->setCursor(x_mouse, y_mouse);
    repaint();
    if(event->button() == Qt::RightButton) {
      my_GUI->rightButton();
//        if (is_inventory) {
//            try {
//                std::vector<string> cmd_name = my_engine->getCommands(my_GUI->getIndexItemInventory()); //Zé, esse metodo retorna dum std::vector<string> que contem os nomes dos comandos, pra poder passar pra interface do inventario
//                //Zé, como vamos saber se não clicou em nada ?
//                //Zé responde: Colision na veia
//                cerr << cmd_name[0];
//            } catch (const char * err) {
//                cerr << err;
//            }
//        }
    } else {
        my_GUI->leftButton();
    }
}

void Game::myUpdate()
{
    if (game_over) {
        clock->stop();
        return;
    }
    is_battle = my_engine->isBattle();
    if (is_battle && !my_engine->isWalking()) {
//        if (my_engine->isWalking()) { //temp
//            my_engine->update();
//            repaint();
//        } else {
            my_GUI->resetSelectedOption();
            atual_direction = SLEEP;
            clock->setInterval(1000/7);
            disconnect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
            connect(clock, SIGNAL(timeout()), this, SLOT(myBattle()));
            repaint();
//        }
    }
    else {
        my_engine->setPlayerDirection(atual_direction);
        my_engine->update();
        is_battle = false;
        repaint();
    }
}

void Game::myBattle()
{
    if (!is_battle) {
        disconnect(clock, SIGNAL(timeout()), this, SLOT(myBattle()));
        connect(clock, SIGNAL(timeout()), this, SLOT(myUpdate()));
        clock->setInterval(1000/60);
    } else if (!(my_GUI->isBattleDelay())) {
        if (interactive_button) {
            try {
                int ret = my_engine->battle(my_GUI->getSelectedOption());
                mp->setMedia(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(Battle::options_sounds[my_GUI->getSelectedOption()])).absoluteFilePath()));
                mp->play();
                interactive_button = false;
                my_GUI->battleDelayCont();
                my_GUI->setBattleText(QString::number(ret));
            } catch (Exceptions exc) {
                switch (exc) {
                case GAME_OVER:
                    game_over = true;
                    mp->setMedia(QUrl::fromLocalFile(QFileInfo("Music/Stairway to Heaven - Symphonic Led Zeppelin.mp3").absoluteFilePath()));
                    mp->play();
                    is_battle = false;
                    break;
                case CHARACTER_DIE:
                    is_battle = false;
                    break;
                case DODGE:
                    my_GUI->setBattleText("Dodge", Qt::blue);
                    mp->setMedia(QUrl::fromLocalFile(QFileInfo("Music/swing3.wav").absoluteFilePath()));
                    mp->play();
                    interactive_button = false;
                    my_GUI->battleDelayCont();
                    break;
                case MISS:
                    my_GUI->setBattleText("Miss", Qt::red, false);
                    mp->setMedia(QUrl::fromLocalFile(QFileInfo("Music/swing3.wav").absoluteFilePath()));
                    mp->play();
                    interactive_button = false;
                    my_GUI->battleDelayCont();
                    break;
                default:
                    break;
                }
            } catch (const char * err) {
                cerr << err;
            }
        } else if (my_GUI->moveCursorBattle(atual_direction)) {
            mp->setMedia(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(Battle::cursor_change_sound)).absoluteFilePath()));
            mp->play();
        }
    } else {
        my_GUI->battleDelayCont();
    }
    atual_direction = SLEEP;
    repaint();
}
