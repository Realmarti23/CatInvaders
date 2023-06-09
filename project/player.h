#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class Player : public QGraphicsRectItem {
public:
    Player();
    void keyPressEvent(QKeyEvent *event) override;
};

#endif