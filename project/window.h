#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTimer>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow();

private slots:
    void onTick();

private:
    QTimer ticker;
    QRect sq;
    QPoint dir;
};

#endif