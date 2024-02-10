#ifndef POWERPROGRESSBARNORMAL_H
#define POWERPROGRESSBARNORMAL_H
#include <QPainter>
#include <QPainterPath>
#include <QWidget>

class PowerProgressBarNormal : public QWidget
{
    Q_OBJECT
public:
    explicit PowerProgressBarNormal(QWidget *parent = nullptr);
    void update_value(qreal new_value);
    void paintEvent(QPaintEvent *);
private:
    qreal value;
    qreal start_angle;
    qreal stop_angle;
    qreal max_angle;
    QWidget *parent;
};

#endif // POWERPROGRESSBARNORMAL_H
