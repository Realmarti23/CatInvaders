#include "player.h"

Player::Player() {
    setRect(0, 0, 30, 30);
}

void Player::keyPressEvent(QKeyEvent *event) {
    int step = 20;

    switch (event->key()) {
    case Qt::Key_Left:
        if (x() - step >= 0)
            setPos(x() - step, y());
        break;
    case Qt::Key_Right:
        if (x() + rect().width() + step <= 1280)
            setPos(x() + step, y());
        break;
    default:
        break;
    }
}