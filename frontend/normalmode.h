#ifndef NORMALMODE_H
#define NORMALMODE_H
#include "speedprogressbarnormal.h"
#include "batteryprogressbarnormal.h"
#include <QPixmap>
#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include "mode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NormalMode; }
QT_END_NAMESPACE

class NormalMode : public Mode
{
    Q_OBJECT

// Only in order to testing.
public slots:
    void test();
// Only in order to testing.

public:
    NormalMode();
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
    ~NormalMode();

    // Only in order to testing.
    void init(){
        QTimer *timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(test()));
        timer->start(100);
        this->set_battery_level(70);
        this->set_battery_temperature(30);
        this->set_engine_temperature(50);
        }
    // Only in order to testing.


private:
    Ui::NormalMode *ui;
    const qreal max_speed = 150;
    const qreal max_power = 32;
    const qreal max_battery_level = 100;
    qreal actual_speed;
    qreal actual_power;
    qreal actual_battery_level;
    qreal actual_battery_temperature;
    qreal actual_engine_temperature;
    bool caution_status;
    bool left_direction_light_status;
    bool right_direction_light_status;
    bool highbeam_lights_status;
    bool lowbeam_lights_status;
    bool position_lights_status;
    // Only for simulation
    int second_time_period = 10;
    int third_time_period;
    int simulation_stage = 0;

    // Only for simulation
};
#endif // NORMALMODE_H
