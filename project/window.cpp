#include "window.h"
#include <QPainter>
#include <QKeyEvent>

MainWindow::MainWindow() : dir(20, 0) {
    setFixedSize(1280, 720);
    sq = QRect(1280/2, 720, 30, 30);
    connect(&ticker, &QTimer::timeout, this, &MainWindow::onTick);
    ticker.start(500);
}

void MainWindow::onTick() {
    sq.translate(dir);
    update();
}