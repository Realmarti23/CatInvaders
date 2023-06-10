#include "Health.h"
#include "Game.h"
#include <QFont>
#include <QApplication>

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    health = 100;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease() {
    health -=20;
    if (gameOver()){
        game->displayMessage("You Lose!");
        scene()->removeItem(game->player);
        game->canMove = false;
    }

    setPlainText(QString("Health: ") + QString::number(health));

}

int Health::getHealth() {
    return health;
}

bool Health::gameOver() {
    return health < 1;
}
