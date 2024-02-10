#include "dashboard.h"

Dashboard::Dashboard()
{
    this->screen = new NormalMode();
    this->screen->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->screen->show();
}

void Dashboard::change_to_normal(){
    delete this->screen;
    this->screen = new NormalMode();
    this->screen->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->screen->show();
}

void Dashboard::change_to_sport(){
    delete this->screen;
    this->screen = new SportMode();
    this->screen->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->screen->show();
}

