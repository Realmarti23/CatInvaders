#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem {

public:
    Score(QGraphicsItem *parent);
    void increase();
    int getScore();

private:
    int score;
};

#endif