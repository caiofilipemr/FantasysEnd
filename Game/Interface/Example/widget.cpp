#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    barra = new Bar(200, 16, 500, "red");
    barra->setSizeBar(300);
    inv = new Inventory(360,222,30,10);
    test = new Rectangle(0,0,100,100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter *obj = new QPainter(this);
    barra->draw(obj, 10, 10);
    inv->draw(obj);
}

void Widget::mousePressEvent(QMouseEvent * event)
{
  inv->setCursor(event->x(), event->y());
  repaint();
}
