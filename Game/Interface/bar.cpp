#include "bar.h"

Bar::Bar(int width, int height, int size):width(width), height(height), size(size)
{
    size_bar = size;
    prop = float(width)/float(size);
    this->begin_back = new QPixmap("Images/Bar/barBack_horizontalLeft.png");
    this->mid_back = new QPixmap("Images/Bar/barBack_horizontalMid.png");
    this->end_back = new QPixmap("Images/Bar/barBack_horizontalRight.png");
}

Bar::~Bar()
{

}

void Bar::setImage(QPixmap * begin, QPixmap * mid, QPixmap *end)
{
    this->begin = begin;
    this->mid = mid;
    this->end = end;
}

void Bar::setSizeBar(int size_bar)
{
    this->size_bar = size_bar;
}

QPixmap Bar::getMid()
{
    int w = (width/size)*size - begin->width() - end->width();
    return mid->copy(0, 0, w, height);
}

QPixmap Bar::getEnd()
{
    return *end;
}

QPixmap Bar::getBegin()
{
    return *begin;
}

int Bar::getW()
{
    return width;
}

int Bar::getH()
{
    return height;
}

void Bar::draw(QPainter *obj, int x, int y)
{
    if(!width) return;

    int w = prop*size;

    //Desenhando o fundo
    obj->drawPixmap(x, y, begin->width(), height, *(this->begin_back));
    obj->drawPixmap(x + begin->width(), y, w, height, *(this->mid_back));
    obj->drawPixmap(x + begin->width() + w, y, end->width(), height, *(this->end_back));

    if(!size_bar) return;

    //Aproximando a barra (Savio enjoado)
    if(size_bar == size) w = prop*size;
    else if(prop * size_bar < end->width()/4) w = 1;
    else w = prop * size_bar  - end->width()/4;

    //Desenhando a barra
    obj->drawPixmap(x, y, begin->width(), height, *(this->begin));
    obj->drawPixmap(x + begin->width(), y, w, height, *(this->mid));
    obj->drawPixmap(x + begin->width() + w, y, end->width(), height, *(this->end));
}
