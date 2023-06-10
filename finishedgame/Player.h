#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem {
    Q_OBJECT
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
public slots:
    void spawnBullet();



};

#endif