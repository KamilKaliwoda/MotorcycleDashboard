#include "batteryprogressbarnormal.h"

BatteryProgressBarNormal::BatteryProgressBarNormal(QWidget *parent) : QWidget(parent), value(0)
{
    setMinimumSize(250, 500);
    start_angle = -35;
    stop_angle = 30;

    max_angle = std::abs(start_angle) + std::abs(stop_angle);
}

void BatteryProgressBarNormal::update_value(qreal new_value) {
  if (value == new_value) return;
  value = new_value;
  update();
}

void BatteryProgressBarNormal::paintEvent(QPaintEvent *) {
  qreal angle = value * max_angle;
  QPainter painter(this);
  painter.fillRect(rect(), Qt::black);
  painter.setRenderHint(QPainter::Antialiasing);
  QPainterPath value_path, background_path;
  QPen value_pen, background_pen;

  background_path.moveTo(11, 295);
  background_path.arcTo(QRectF(-390, -50, 440, 440), start_angle, max_angle);
  background_pen.setCapStyle(Qt::FlatCap);
  background_pen.setDashPattern(QVector<qreal>{0.2, 0.2});
  background_pen.setColor(QColor("#404040"));
  background_pen.setWidth(10);
  painter.strokePath(background_path, background_pen);

  if (angle > 0){
      value_path.moveTo(11, 295);
      value_pen.setWidth(10);
      value_pen.setColor(QColor("#009999"));
      value_pen.setCapStyle(Qt::FlatCap);
      value_pen.setDashPattern(QVector<qreal>{0.2, 0.2});
      value_path.arcTo(QRectF(-390, -50, 440, 440), start_angle, angle);
      painter.strokePath(value_path, value_pen);
  }
}
