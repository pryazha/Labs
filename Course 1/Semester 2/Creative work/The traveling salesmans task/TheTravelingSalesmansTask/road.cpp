#define _USE_MATH_DEFINES
#include "road.h"
#include <cmath>
Road::Road(City* f, City* s, double l, QGraphicsItem* parent) : QGraphicsItem(parent)
{
    first_city = f;
    second_city = s;
    length = l;
    setFlag(QGraphicsItem::ItemIsFocusable);
    color = Qt::black;
}

Road::Road(const Road& r){
    first_city = r.first_city;
    second_city = r.second_city;
    length = r.length;
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QString Road::double_to_str(double in){
    QString result = QString::fromStdString(std::to_string(in));
    double intpart;
    while (result.back() == '0'){
        result.remove(result.length() - 1, 1);
    }
    if (modf(in, &intpart) == 0.0){
        result.remove(result.length() - 1, 1);
    }
    return result;
}

void Road::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setRenderHints(QPainter::Antialiasing);
    painter->setPen(color);
    qreal fx = first_city->pos().x() + 25;
    qreal fy = first_city->pos().y() + 25;
    qreal sx = second_city->pos().x() + 25;
    qreal sy = second_city->pos().y() + 25;
    qreal angle = -atan(abs(sy - fy) / abs(sx - fx));
    if (sx - fx < 0) {
        if (sy - fy < 0) {
            angle += M_PI;
        } else {
            angle = M_PI - angle;
        }
    } else if (sy - fy < 0) {
        angle = -angle;
    }
    qreal del_x, del_y;
    del_x = 15 * sin(angle);
    del_y = 15 * cos(angle);
    QLineF line = QLineF(fx - del_x, fy - del_y, sx - del_x, sy - del_y);
    QLineF vector = line.unitVector();
    vector.setLength(20);
    QPointF point1 = vector.p2();
    vector.setLength(line.length() - 20);
    QPointF point2 = vector.p2();
    painter->drawLine(QLineF(point1, point2));
    vector.setLength(line.length() - 30);
    QLineF arrow_1 = QLineF(point2, vector.p2());
    QLineF arrow_2 = QLineF(point2, vector.p2());
    arrow_1.setAngle(arrow_1.angle() - 30);
    arrow_2.setAngle(arrow_2.angle() + 30);
    painter->drawLine(arrow_1);
    painter->drawLine(arrow_2);
    QFontMetrics fm(painter->font());
    QString ln = double_to_str(length);
    int tw = fm.width(ln);
    qreal rotate_angle = -line.angle();
    QPointF center = line.center();
    qreal text_x = center.x() * cos(M_PI * rotate_angle / 180) + center.y() * sin(M_PI * rotate_angle / 180);
    qreal text_y = -center.x() * sin(M_PI * rotate_angle / 180) + center.y() * cos(M_PI * rotate_angle / 180);
    painter->rotate(rotate_angle);
    painter->drawText(text_x - tw/2, text_y - 5, ln);
    painter->rotate(-rotate_angle);
}

QRectF Road::boundingRect() const {
    return QRectF(0, 0, 30, 30);
}

bool operator== (const Road &r1, const Road &r2) {
    return r1.first_city == r2.first_city && r1.second_city == r2.second_city;
}

void Road::selected_color() {
    color = Qt::red;
}

void Road::unselected_color() {
    color = Qt::black;
}


