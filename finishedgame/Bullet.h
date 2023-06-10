#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem {
    Q_OBJECT



public:
    Bullet(bool isFromEnemy);
    bool isEnemy;
public slots:
    void move();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;
};

#endif
