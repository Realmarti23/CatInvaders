#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <cstdlib>
#include "Game.h"
#include "Bullet.h"
#include <iostream>

extern Game * game;

Enemy::Enemy(int x, int y): QObject(), QGraphicsRectItem() {
    srand((unsigned) x * y);

    setPos(x,y);
    setRect(-55, -55, 110, 110);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnBullet()));

    int spawn_time = rand() % 50;
    timer->start(spawn_time * 200);

    QTimer * timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(moveRandom()));

    int move_time = rand() % 100;
    timer->start(spawn_time * 200);
    timer2->start(move_time * 500);
}

QRectF Enemy::boundingRect() const {
    return QRectF(-50, -50, 110, 110);
}

void Enemy::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::gray);
    painter->setPen(Qt::black);

    QPainterPath path;
    path.addEllipse(-40, -40, 80, 80);
    path.addEllipse(-30, -15, 20, 30);
    path.addEllipse(10, -15, 20, 30);
    path.addEllipse(-25, -5, 50, 60);
    path.addEllipse(-25, -20, 15, 15);
    path.addEllipse(10, -20, 15, 15);
    path.moveTo(-15, 10);
    path.lineTo(15, 10);
    path.lineTo(10, 20);
    path.lineTo(-10, 20);
    path.closeSubpath();

    painter->drawPath(path);
}

void Enemy::spawnBullet() {
    Bullet * bullet = new Bullet(true);
    bullet->setPos(x() + rect().width()/2 - 55, y());
    scene()->addItem(bullet);
}

void Enemy::moveRandom() {
    srand((unsigned) time(0));

    int move = rand() % 100;
    int moveX = x() + (move - 50);
    moveX = std::clamp(moveX, (int)rect().width() /2,  1280 - (int)rect().width() /2);
    setPos(moveX, y());
}