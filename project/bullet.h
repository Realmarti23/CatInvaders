#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QTimer>

class Bullet : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Bullet();
public slots:
    void move();

private:
    QTimer timer;
};

#endif