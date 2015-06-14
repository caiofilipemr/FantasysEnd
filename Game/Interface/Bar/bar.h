#ifndef BAR_H
#define BAR_H

#include <QPainter>
#include <iostream>

class Bar
{
public:
    Bar(int width, int height, int size, const char * color);
    ~Bar();
    void setSizeBar(int size_bar);
    QPixmap getBegin();
    QPixmap getMid();
    QPixmap getEnd();
    int getW();
    int getTotalW();
    int getH();
    QPixmap *begin, *mid, *end, *begin_back, *mid_back, *end_back;
    void draw(QPainter *obj, int x, int y);

private:
    int width, height, size, size_bar;
    float prop;
};

#endif // BAR_H
