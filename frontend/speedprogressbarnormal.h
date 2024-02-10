#ifndef SPEEDPROGRESSBARNORMAL_H
#define SPEEDPROGRESSBARNORMAL_H
#include <QPainter>
#include <QPainterPath>
#include <QWidget>

class SpeedProgressBarNormal : public QWidget
{
    Q_OBJECT
public:
    explicit SpeedProgressBarNormal(QWidget *parent = nullptr);
    void update_value(qreal new_value);
    void paintEvent(QPaintEvent *);
private:
    qreal value;
    QWidget *parent;

};

#endif // SPEEDPROGRESSBARNORMAL_H

