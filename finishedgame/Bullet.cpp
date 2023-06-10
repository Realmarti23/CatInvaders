#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game;

Bullet::Bullet(bool isFromEnemy) {
    setRect(0,0,10,50);

    isEnemy = isFromEnemy;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(20);

}

void Bullet::move() {

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int id = 0, n = colliding_items.size(); id < n; ++id) {
        bool isHitEnemy = typeid(*(colliding_items[id])) == typeid(Enemy) && !isEnemy;
        if (isHitEnemy) {
            game->score->increase();

            scene()->removeItem(colliding_items[id]);
            scene()->removeItem(this);

            auto allItems = game->scene->items();
            int enemyCount = 0;
            for (int i = 0; i < allItems.count(); ++i) {
                if(typeid(*(allItems[i])) == typeid(Enemy))
                    enemyCount++;
            }

            if(enemyCount <= 0) {
                game->displayMessage("You Win");
            }

            delete colliding_items[id];
            delete this;

            return;
        } else if(typeid(*(colliding_items[id])) == typeid(Player)) {
            game->health->decrease();

            scene()->removeItem(this);

            delete this;

            return;
        }
    }

    setPos(x(), y() + (isEnemy ? 10 : -10));

    if (pos().y() + rect().height() < 0 || pos().y() > 720){
        scene()->removeItem(this);
        delete this;
    };
}

QRectF Bullet::boundingRect() const {
    return QRectF(-5, -10, 10, 20);
}

void Bullet::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::red);
    painter->setPen(Qt::NoPen);

    QPainterPath path;
    path.moveTo(-5, 0);
    path.lineTo(-2, -6);
    path.lineTo(2, -6);
    path.lineTo(5, 0);
    path.lineTo(2, 6);
    path.lineTo(-2, 6);
    path.closeSubpath();

    painter->drawPath(path);
}