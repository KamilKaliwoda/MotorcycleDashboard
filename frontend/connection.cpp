#include "connection.h"

void Connection::execute_code_from_input(){
    QString output(process->readAllStandardOutput());
    int code = output.toInt();
    int value_type = code / 1000;
    int value = code % 1000;
    if (value_type == valueTypes::speed) {
        this->w->get_screen()->set_speed(value);
    } else if (value_type == valueTypes::power) {
        this->w->get_screen()->set_power(value);
    } else if (value_type == valueTypes::battery_level) {
        this->w->get_screen()->set_battery_level(value);
    } else if (value_type == valueTypes::engine_temperature) {
        this->w->get_screen()->set_engine_temperature(value);
    } else if (value_type == valueTypes::battery_temperature) {
        this->w->get_screen()->set_battery_temperature(value);
    } else if (value_type == valueTypes::caution) {
        if (value == 1) {
            this->w->get_screen()->set_caution();
        } else if (value == 0) {
           this->w->get_screen()->reset_caution();
        }
    } else if (value_type == valueTypes::left_direction_light) {
        if (value == 1) {
            this->w->get_screen()->set_left_direction_light();
        } else if (value == 0) {
           this->w->get_screen()->reset_left_direction_light();
        }
    } else if (value_type == valueTypes::right_direction_light) {
        if (value == 1) {
            this->w->get_screen()->set_right_direction_light();
        } else if (value == 0) {
           this->w->get_screen()->reset_right_direction_light();
        }
    } else if (value_type == valueTypes::highbeam_lights) {
        if (value == 1) {
            this->w->get_screen()->set_highbeam_lights();
        } else if (value == 0) {
           this->w->get_screen()->reset_highbeam_lights();
        }
    } else if (value_type == valueTypes::lowbeam_lights) {
        if (value == 1) {
            this->w->get_screen()->set_lowbeam_lights();
        } else if (value == 0) {
           this->w->get_screen()->reset_lowbeam_lights();
        }
    } else if (value_type == valueTypes::position_lights) {
        if (value == 1) {
            this->w->get_screen()->set_position_lights();
        } else if (value == 0) {
           this->w->get_screen()->reset_position_lights();
        }
    } else if (value_type == valueTypes::dashboard_mode) {
        if (value == 1) {
            this->w->change_to_normal();
        } else if (value == 2) {
           this->w->change_to_sport();
        }
    }
}


Connection::Connection(){
    w = new Dashboard();
    w->change_to_normal();
    process = new QProcess(this);
    process->setCurrentReadChannel(QProcess::StandardOutput);
    connect(process, SIGNAL(readyRead()), this, SLOT(execute_code_from_input()));
    process->start("python", QStringList() << "C:/Users/kkaliwoda/Desktop/repositories/python_backend_test/communication_test.py");
}
