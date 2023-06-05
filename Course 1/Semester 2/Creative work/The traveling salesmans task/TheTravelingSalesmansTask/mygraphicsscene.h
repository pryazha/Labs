#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "city.h"

class QGraphicsSceneMouseEvent;
class QPointF;
class QColor;

class myGraphicsScene :  public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myGraphicsScene(QObject *parent = 0);
    bool choosing_cities;
    void recheck_selected();

public slots:

signals:
    void city_chosen(City*);
    void item_selected(QGraphicsItem*);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    QPen* pen;
    QBrush* brush;
};

#endif // MYGRAPHICSSCENE_H
