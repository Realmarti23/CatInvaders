#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Enemy.h"

class Game: public QGraphicsView {
    Q_OBJECT

public:
    Game(QWidget * parent=NULL);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    int sceneWidth;
    int sceneHeight;

    std::vector<Enemy*> enemies;

    bool canShoot = true;
    bool canMove = true;
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void start();



    void canShootFunc();

    void displayMessage(const std::string &message);
};

#endif
