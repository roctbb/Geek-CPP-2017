#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    for (int i=0; i<NUM; i++)
        balls[i] = new Ball(width(), height());
    connect(&timer, SIGNAL(timeout()), this, SLOT(moveAll()));
    timer.start(40);
}

Widget::~Widget()
{
    for (int i=0; i<NUM; i++)
        delete balls[i];
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    for (int i=0; i<NUM; i++)
        balls[i]->draw(painter);

}
void Widget::moveAll()
{
    for (int i=0; i<NUM; i++)
        balls[i]->move(width(), height());
    this->repaint();
}
