#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

QRectF Player::boundingRect() const {
    return QRectF(-50, -50, 100, 100);  // Rectangle size adjusted to fit the fish shape
}

void Player::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::yellow);
    painter->setPen(Qt::black);

    QPainterPath path;
    path.addEllipse(-30, -30, 60, 60);     // Head
    path.addEllipse(-45, -15, 20, 40);     // Left ear
    path.addEllipse(25, -15, 20, 40);      // Right ear
    path.addEllipse(-20, 5, 40, 40);       // Body
    path.addEllipse(-40, 10, 20, 20);      // Left eye
    path.addEllipse(20, 10, 20, 20);       // Right eye
    path.moveTo(-30, 30);                   // Mouth
    path.lineTo(30, 30);
    path.lineTo(20, 40);
    path.lineTo(-20, 40);
    path.closeSubpath();


    painter->drawPath(path);
}

void Player::spawnBullet() {
    Bullet * bullet = new Bullet(false);
    bullet->setPos(x() + rect().width()/2 - 55, y() - 70);
    scene()->addItem(bullet);
}

