#ifndef WRITE_H
#define WRITE_H

#include <QPixmap>
#include <QPainter>
#include <iostream>

class Write
{
private:
    static const QString letters_and_numbers[53], slash;
    static const int slash_width, all_number_height;
public:
    Write();
    static void writeHPorMP(QString p, QString p_max, int bar_x, int bar_y, int bar_w, int bar_h, QPainter *painter);
    static void writeText(QString text, int x, int y, QPainter *painter, bool red = false);
    static void writeText(QString text, int x, int y, int width, int height, QPainter *painter, bool red = false);
};

#endif // WRITE_H
