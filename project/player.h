#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class Player : public QGraphicsRectItem {
public:
    Player();

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* options, QWidget* widget) override;

    QRect sq;
    QPoint dir;
};

#endif