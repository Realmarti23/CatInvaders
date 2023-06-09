#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTimer>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow();
protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onTick();

private:
    QTimer ticker;
    QRect sq;
    QPoint dir;
};

#endif