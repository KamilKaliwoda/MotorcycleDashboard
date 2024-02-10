#include "powerprogressbarsport.h"

PowerProgressBarSport::PowerProgressBarSport(QWidget *parent) : QWidget(parent), value(0)
{
    setMinimumSize(800, 380);
    start_angle = -16.5 * 16;
    stop_angle = -90 * 16;

    max_angle = stop_angle - start_angle;
}

void PowerProgressBarSport::update_value(qreal new_value) {
    if (value == new_value) return;
    value = new_value;
    update();
}

void PowerProgressBarSport::paintEvent(QPaintEvent *){
    //background

    QPainter painter(this);
    painter.setPen(QPen(Qt::red));
    painter.setBrush(Qt::black);
    painter.drawPie(QRectF(-50, 0, 1700, 700), -180 * 16, -90 * 16);

    // progress bar
    int span_angle = start_angle + (max_angle * value);
    QConicalGradient gradient(1000, 400, -90);
    gradient.setColorAt(0.75, QColor("#FFFF99"));
    gradient.setColorAt(0.70, QColor("#FF9933"));
    gradient.setColorAt(0.65, QColor("#CC0000"));
    painter.setPen(QPen(Qt::red));
    painter.setBrush(QBrush(gradient));
    painter.drawPie(QRectF(-50, 0, 1700, 700), -180 * 16, span_angle);

    // mask
    painter.setPen(QPen(Qt::red));
    painter.setBrush(Qt::black);
    painter.drawPie(QRectF(-80, 90, 1500, 600), -180 * 16, -360 * 16);

}
