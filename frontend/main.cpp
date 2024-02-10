#include "normalmode.h"
#include "connection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection *c = new Connection();
    //Dashboard *w = new Dashboard();
    //w.set_speed(400);
//    w.set_battery_level(45);
//    w.set_power(123);
//    w.set_battery_temperature(42);
//    w.set_engine_temperature(123);
    //w->change_to_sport();
    //w->change_to_normal();
    //w->get_screen()->init();
    return a.exec();
}
