#ifndef ROAD_H
#define ROAD_H

#include "city.h"

class Road : public QGraphicsItem {
public:
    double length;
    City* first_city;
    City* second_city;

    Road(City*, City*, double, QGraphicsItem* parent = nullptr);
    Road(const Road& road);

    void selected_color();
    void unselected_color();

    friend bool operator ==(const Road&, const Road&);

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    QRectF boundingRect() const override;
    QString double_to_str(double);
    QColor color;
};

#endif // ROAD_H
