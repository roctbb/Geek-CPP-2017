#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPaintEvent>
#include "ball.h"

namespace Ui {
class Widget;
}

const int NUM = 5;

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
    Ball * balls[NUM];
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void paintEvent(QPaintEvent * e);
protected slots:
    void moveAll();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
