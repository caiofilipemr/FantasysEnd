#ifndef WRITE_H
#define WRITE_H

#include <QPixmap>
#include <QPainter>

class Write
{
private:
    static const QString letters_and_numbers[43], slash;
    static const int slash_width, all_number_height;
public:
    Write();
    static void writeHPorMP(QString p, QString p_max, int bar_x, int bar_y, int bar_w, int bar_h, QPainter *painter);
    static void writeText(QString text, int x, int y, QPainter *painter);
};

#endif // WRITE_H
