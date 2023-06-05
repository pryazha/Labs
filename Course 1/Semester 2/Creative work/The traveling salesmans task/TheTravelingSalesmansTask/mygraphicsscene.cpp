#include "mygraphicsscene.h"

myGraphicsScene::myGraphicsScene(QObject *parent) : QGraphicsScene(parent){
    pen = new QPen(Qt::black);
    brush = new QBrush(Qt::blue);
    choosing_cities = false;
}

void myGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    QGraphicsScene::update();
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void myGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    QGraphicsScene::mousePressEvent(mouseEvent);
    emit item_selected(QGraphicsScene::focusItem());
    if (choosing_cities) {
        if (QGraphicsScene::focusItem()) {
            QGraphicsItem* item = QGraphicsScene::focusItem();
            City* c = dynamic_cast<City*>(item);
            if (c)
                emit city_chosen(c);
        }
    }
    QGraphicsScene::update();
}

void myGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
    emit item_selected(QGraphicsScene::focusItem());
}

void myGraphicsScene::recheck_selected() {
    emit item_selected(QGraphicsScene::focusItem());
}
