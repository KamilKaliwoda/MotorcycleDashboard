#ifndef CONNECTION_H
#define CONNECTION_H
#include <iostream>
#include <string>
#include <QProcess>
#include "dashboard.h"

enum valueTypes {
    speed = 1,
    power = 2,
    battery_level = 3,
    engine_temperature = 4,
    battery_temperature = 5,
    caution = 6,
    left_direction_light = 7,
    right_direction_light = 8,
    highbeam_lights = 9,
    lowbeam_lights = 10,
    position_lights = 11,
    dashboard_mode = 12
};

class Connection: public QObject{
    Q_OBJECT
public:
    Connection();
private slots:
    void execute_code_from_input();
private:
    Dashboard *w;
    QProcess *process;
};

#endif // CONNECTION_H
