#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "window.h"
#include "player.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    MainWindow window1;
    window1.show();


    return app.exec();
}