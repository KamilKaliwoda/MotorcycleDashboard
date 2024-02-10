#ifndef MODE_H
#define MODE_H

#include <QMainWindow>

class Mode : public QMainWindow
{
public:
    virtual void set_speed(int speed) = 0;
    virtual void set_power(int power) = 0;
    virtual void set_battery_level(int battery_level) = 0;
    virtual void set_battery_temperature(int battery_temperature) = 0;
    virtual void set_engine_temperature(int engine_temperature) = 0;
    virtual void set_caution() = 0;
    virtual void reset_caution() = 0;
    virtual void set_left_direction_light() = 0;
    virtual void reset_left_direction_light() = 0;
    virtual void set_right_direction_light() = 0;
    virtual void reset_right_direction_light() = 0;
    virtual void set_highbeam_lights() = 0;
    virtual void reset_highbeam_lights() = 0;
    virtual void set_lowbeam_lights() = 0;
    virtual void reset_lowbeam_lights() = 0;
    virtual void set_position_lights() = 0;
    virtual void reset_position_lights() = 0;
    //// testing
    virtual void init() = 0;
    //// testing
    virtual ~Mode() = default;
};

#endif // MODE_H
