#include "speedprogressbarnormal.h"

SpeedProgressBarNormal::SpeedProgressBarNormal(QWidget *parent) : QWidget(parent), value(0)
{
    setMinimumSize(500, 500);
}

void SpeedProgressBarNormal::update_value(qreal new_value) {
  if (value == new_value) return;
  value = new_value;
  update();
}

void SpeedProgressBarNormal::paintEvent(QPaintEvent *) {
  qreal angle = value * 360;
  QPainter painter(this);
  painter.fillRect(rect(), Qt::black);
  painter.setRenderHint(QPainter::Antialiasing);

  QConicalGradient conicalGradient(170,170, -90);
  conicalGradient.setColorAt(1, QColor("#202020"));
  conicalGradient.setColorAt(0.5, QColor("#009999"));
  conicalGradient.setColorAt(0, QColor("#00CCCC"));

  QPainterPath background_path, value_path, value_pitch_path, empty_pitch_path;
  QPen background_pen, value_pen(QBrush(conicalGradient), 25), value_pitch_pen, empty_pitch_pen;

  background_path.moveTo(170, 320);
  background_path.arcTo(QRectF(20, 20, 300, 300), 270, -360);
  background_pen.setCapStyle(Qt::FlatCap);
  background_pen.setColor(QColor("#202020"));
  background_pen.setWidth(25);
  painter.strokePath(background_path, background_pen);

  value_path.moveTo(170, 320);
  value_path.arcTo(QRectF(20, 20, 300, 300), 270, -angle);
  value_pen.setCapStyle(Qt::FlatCap);
  //value_pen.setColor(QColor("#009999"));
  painter.strokePath(value_path, value_pen);

  empty_pitch_path.moveTo(170, 300);
  empty_pitch_path.arcTo(QRectF(40, 40, 260, 260), 270, -360);
  empty_pitch_pen.setCapStyle(Qt::FlatCap);
  empty_pitch_pen.setDashPattern(QVector<qreal>{0.25, 3.0});
  empty_pitch_pen.setColor(QColor("#404040"));
  empty_pitch_pen.setWidth(14);
  painter.strokePath(empty_pitch_path, empty_pitch_pen);

  value_pitch_path.moveTo(170, 300);
  value_pitch_pen.setWidth(14);
  value_pitch_pen.setColor(QColor("#00CCCC"));
  value_pitch_pen.setCapStyle(Qt::FlatCap);
  value_pitch_pen.setDashPattern(QVector<qreal>{0.25, 3.0});
  value_pitch_path.arcTo(QRectF(40, 40, 260, 260), 270, -angle);
  painter.strokePath(value_pitch_path, value_pitch_pen);
}
