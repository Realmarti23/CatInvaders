#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsView>

class MainWindow : public QGraphicsView {
    Q_OBJECT

public:
    MainWindow();

private:
    QTimer ticker;
    QRect sq;
    QPoint dir;
    QGraphicsScene* scene;

    void keyPressEvent(QKeyEvent *event) override;
};

#endif