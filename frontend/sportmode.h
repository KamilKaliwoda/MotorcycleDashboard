#ifndef SPORTMODE_H
#define SPORTMODE_H
#include "mode.h"
#include <QMainWindow>
#include <QTimer>


namespace Ui {
class SportMode;
}

class SportMode : public Mode
{
    Q_OBJECT
// Only in order to testing.
public slots:
    void test();
// Only in order to testing.

public:
    explicit SportMode();
    void set_speed(int speed);
    void set_power(int power);
    void set_battery_level(int battery_level);
    void set_battery_temperature(int battery_temperature);
    void set_engine_temperature(int engine_temperature);
    void set_caution();
    void reset_caution();
    void set_left_direction_light();
    void reset_left_direction_light();
    void set_right_direction_light();
    void reset_right_direction_light();
    void set_highbeam_lights();
    void reset_highbeam_lights();
    void set_lowbeam_lights();
    void reset_lowbeam_lights();
    void set_position_lights();
    void reset_position_lights();
    ~SportMode();

    // Only in order to testing.
    void init(){
        QTimer *timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(test()));
        timer->start(100);
        set_caution();
        set_left_direction_light();
        set_right_direction_light();
        set_highbeam_lights();
        set_lowbeam_lights();
        set_position_lights();
        }
    // Only in order to testing.

private:
    Ui::SportMode *ui;
    const qreal max_speed = 150;
    const qreal max_power = 32;
    const qreal max_battery_level = 100;
    qreal actual_speed;
    qreal actual_power;
    qreal actual_battery_level;
    const qreal battery_level_low = 20;
    const qreal battery_level_high = 70;
    qreal actual_battery_temperature;
    const qreal battery_temperature_low = 50;
    const qreal battery_temperature_high = 100;
    qreal actual_engine_temperature;
    const qreal engine_temperature_low = 90;
    const qreal engine_temperature_high = 150;
};

#endif // SPORTMODE_H
