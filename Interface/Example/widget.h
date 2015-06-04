#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QMouseEvent>
#include "inventory.h"
#include "bar.h"

namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    Ui::Widget *ui;
    Bar *barra;
    Inventory *inv;
};

#endif // WIDGET_H
