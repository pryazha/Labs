#ifndef CITY_H
#define CITY_H

#include <QGraphicsItem>
#include <QPainter>

class City : public QGraphicsItem {
public:
    QString name;

    City(QGraphicsItem* parent = nullptr);
    City(QString name, int posX, int posY, QGraphicsItem* parent = nullptr);
    City(const City&);

    void set_number(QString number);
    void selected_color();
    void unselected_color();

    friend bool operator ==(const City&, const City&);

private:
    int posX;
    int posY;
    QString number;
    QColor color;

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // CITY_H
