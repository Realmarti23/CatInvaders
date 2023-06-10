#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsRectItem {
    Q_OBJECT



public:
    Enemy(int x, int y);
    int speed;

public slots:

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void spawnBullet();

    void moveRandom();
};

#endif
