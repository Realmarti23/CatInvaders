#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

Bullet::Bullet() {
    setRect(0, 0, 5, 10);

    connect(&timer, &QTimer::timeout, this, &Bullet::move);

    timer.start(50);
}

void Bullet::move() {
    setPos(x(), y() - 10);

    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}