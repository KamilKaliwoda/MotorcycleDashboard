#ifndef POWERPROGRESSBARSPORT_H
#define POWERPROGRESSBARSPORT_H
#include <QPainter>
#include <QPainterPath>
#include <QWidget>

class PowerProgressBarSport : public QWidget
{
    Q_OBJECT
public:
    explicit PowerProgressBarSport(QWidget *parent = nullptr);
    void update_value(qreal new_value);
    void paintEvent(QPaintEvent *);
private:
    qreal value;
    qreal start_angle;
    qreal stop_angle;
    qreal max_angle;
    QWidget *parent;
};

#endif // POWERPROGRESSBARSPORT_H
