#ifndef DASHBOARD_H
#define DASHBOARD_H
#include "normalmode.h"
#include "sportmode.h"

class Dashboard: public QObject
{
    Q_OBJECT
public:
    Dashboard();
    Mode *get_screen() const {return this->screen;};
    void change_to_sport();
    void change_to_normal();
private:
    Mode *screen;
};

#endif // DASHBOARD_H


