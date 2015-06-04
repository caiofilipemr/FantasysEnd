#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    barra = new Bar(90, 18, 500);
    barra->setImage(new QPixmap("Images/Bar/barRed_horizontalLeft.png"),
                    new QPixmap("Images/Bar/barRed_horizontalMid.png"),
                    new QPixmap("Images/Bar/barRed_horizontalRight.png"));
    barra->setSizeBar(450);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter *obj = new QPainter(this);
    barra->draw(obj, 10, 10);
}
