#include "city.h"

City::City(QGraphicsItem* parent) : QGraphicsItem(parent) {
    name = "";
    posX = 0;
    posY = 0;
    color = Qt::yellow;
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    number = "";
}
City::City(QString name, int posX, int posY, QGraphicsItem* parent) : QGraphicsItem(parent) {
    this->name = name;
    this->posX = posX;
    this->posY = posY;
    color = Qt::yellow;
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    number = "";
}
City::City(const City& other) {
    name = other.name;
    posX = other.posX;
    posY = other.posY;
    color = Qt::yellow;
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    number = "";
}

void City::set_number(QString number) {
    this->number = number;
}
void City::selected_color() {
    color = Qt::red;
}
void City::unselected_color() {
    color = Qt::yellow;
}

bool operator ==(const City& c1, const City& c2) {
    return c1.name == c2.name;
}

void City::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setRenderHints(QPainter::Antialiasing);
    painter->setBrush(color);
    painter->drawEllipse(0, 0, 50, 50);

    QFontMetrics fm(painter->font());
    int tw = fm.width(name);
    painter->drawText(25 - tw/2, 30, name);
    tw = fm.width(number);
    painter->drawText(25 - tw/2, -5, number);
}
QRectF City::boundingRect() const {
    return QRectF(posX, posY, 50, 50);
}
