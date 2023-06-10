#include <QPaintEvent>
#include <QPainter>
#include "player.h"

Player::Player() : sq(1280/2,720/2, 20, 20), dir(20, 0) {

}

void Player::paint(QPainter* painter, const QStyleOptionGraphicsItem* options, QWidget* widget) {
    painter->setBrush(Qt::black);
    painter->drawRect(sq);
}