#include "Game.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QKeyEvent>
#include "Enemy.h"
#include "Bullet.h"

#include <QFileInfo>
#include <iostream>

Game::Game(QWidget * parent) {

    sceneWidth = 1024;
    sceneHeight = 768;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(sceneWidth, sceneHeight);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
    setScene(scene);

    setFocusPolicy(Qt::FocusPolicy::StrongFocus);
}


void Game::start() {
    scene->clear();

    player = new Player();
    int playerWidth = 100;
    int playerHeight = 100;
    player->setRect(0,0, playerWidth, playerHeight);
    player->setPos(scene->width()/2 - player->rect().width()/2,
                   scene->height() - player->rect().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    int yTextOffset = 25;
    health->setPos(health->x(), health->y() + yTextOffset);
    scene->addItem(health);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            Enemy* enemy = new Enemy(1280 / 6 * i + 1280 / 12, 720 / 6 * j + 720 / 10);
            scene->addItem(enemy);
            enemies.push_back(enemy);
        }
    }
}

void Game::displayMessage(const std::string& message) {

    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString::fromStdString(message));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int xTitlePos = this->width()/2 - titleText->boundingRect().width()/2;
    int yTitlePos = 150;
    titleText->setPos(xTitlePos, yTitlePos);
    scene->addItem(titleText);
    canMove = false;
}

void Game::keyPressEvent(QKeyEvent *event) {
    if(!canMove)
        return;

    switch(event->key()) {
        case Qt::Key_A:
            if (player->pos().x() > 0)
                player->setPos(player->x()-20, player->y());
            break;
        case Qt::Key_D:
            if (player->pos().x() + 100 < (sceneWidth))
                player->setPos(player->x()+20, player->y());
            break;

        case Qt::Key_Space:
            if(canShoot) {
                player->spawnBullet();
                canShoot = false;
                QTimer::singleShot(500, this, SLOT(canShootFunc()));
            }
            break;
    }
}

void Game::canShootFunc() {
    canShoot = true;
}
