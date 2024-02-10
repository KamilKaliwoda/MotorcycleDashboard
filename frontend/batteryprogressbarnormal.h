#ifndef BATTERYPROGRESSBARNORMAL_H
#define BATTERYPROGRESSBARNORMAL_H
#include <QPainter>
#include <QPainterPath>
#include <QWidget>
#include <cstdlib>

class BatteryProgressBarNormal : public QWidget
{
    Q_OBJECT
public:
    explicit BatteryProgressBarNormal(QWidget *parent = nullptr);
    void update_value(qreal new_value);
    void paintEvent(QPaintEvent *);

private:
    qreal value;
    qreal start_angle;
    qreal stop_angle;
    qreal max_angle;
    QWidget *parent;

};

#endif // BATTERYPROGRESSBARNORMAL_H
