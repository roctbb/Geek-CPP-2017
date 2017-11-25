#include "ball.h"

Ball::Ball(int w, int h)
{
    // устанавливаем радиус
    r = 15 + rand()%15;
    // устанавливанием координаты
    point.setX( r + rand()%(w - 2*r) );
    point.setY( r + rand()%(h - 2*r) );
    // придумываем цвет
    color = QColor::fromRgb(rand()%256, rand()%256, rand()%256);
    // устанавливаем скорости
    vx = 5 + rand()%15;
    vy = 5 + rand()%15;
    if (rand()%2==0) vx *= -1;
    if (rand()%2==0) vy *= -1;
}

void Ball::move(int w, int h)
{
    point += QPoint(vx,vy);
}

void Ball::draw(QPainter &painter)
{
    painter.setBrush(QBrush(color, Qt::Dense7Pattern));
    painter.drawEllipse(point, r, r);
}
