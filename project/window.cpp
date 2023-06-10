#include "window.h"
#include "player.h"
#include <QPainter>
#include <QKeyEvent>

MainWindow::MainWindow() {
    setFixedSize(1280, 720);

    scene = new QGraphicsScene(0,0,1280,720);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(scene);

    Player player;
    player.setFlag(QGraphicsItem::ItemIsFocusable);
    scene->setFocus();
    scene->addItem(&player);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    int step = 20;

    switch (event->key()) {
        case Qt::Key_Left:
            dir.setX(-20);
            dir.setY(0);
            break;
        case Qt::Key_Right:
            dir.setX(20);
            dir.setY(0);
            break;
        default:
            break;

    }
}