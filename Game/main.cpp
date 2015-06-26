#include "game.h"
#include <QApplication>
#include <time.h>
#include <cstdlib>


int main(int argc, char *argv[])
{
    try {
        srand(time(NULL));
        QApplication a(argc, argv);
        Game w;
        w.show();

        return a.exec();
    } catch (std::bad_alloc e) { cerr << e.what(); return 0; }
}
