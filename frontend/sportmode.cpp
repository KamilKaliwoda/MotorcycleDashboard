#include "sportmode.h"
#include "ui_sportmode.h"

SportMode::SportMode(): ui(new Ui::SportMode)
{
    ui->setupUi(this);
    QPixmap batteryTemperatureIconSport(":/sport/sport/BatteryTemperatureIconGreenSport.png");
    ui->batteryTemperatureIcon->setPixmap(batteryTemperatureIconSport.scaled(ui->batteryTemperatureIcon->width(), ui->batteryTemperatureIcon->height(), Qt::KeepAspectRatio));
    QPixmap engineTemperatureIconSport(":/sport/sport/EngineTemperatureIconGreenSport.png");
    ui->engineTemperatureIcon->setPixmap(engineTemperatureIconSport.scaled(ui->engineTemperatureIcon->width(), ui->engineTemperatureIcon->height(), Qt::KeepAspectRatio));
    QPixmap batteryIconSport(":/sport/sport/BatteryLevelIconGreenSport.png");
    ui->batteryIcon->setPixmap(batteryIconSport.scaled(ui->batteryIcon->width(), ui->batteryIcon->height(), Qt::KeepAspectRatio));
    QPixmap cautionIconSport(":/sport/sport/CautionIconSport.png");
    ui->cautionIndicator->setPixmap(cautionIconSport.scaled(ui->cautionIndicator->width(), ui->cautionIndicator->height(), Qt::KeepAspectRatio));
    ui->cautionIndicator->setVisible(false);
    QPixmap rightDirectionIconSport(":/sport/sport/RightDirectionIconSport.png");
    ui->rightDirection->setPixmap(rightDirectionIconSport.scaled(ui->rightDirection->width(), ui->rightDirection->height(), Qt::KeepAspectRatio));
    ui->rightDirection->setVisible(false);
    QPixmap leftDirectionIconSport(":/sport/sport/LeftDirectionIconSport.png");
    ui->leftDirection->setPixmap(leftDirectionIconSport.scaled(ui->leftDirection->width(), ui->leftDirection->height(), Qt::KeepAspectRatio));
    ui->leftDirection->setVisible(false);
    QPixmap lowbeamLightsIconSport(":/sport/sport/LowbeamLightsIconSport.png");
    ui->lowbeamLightsIndicator->setPixmap(lowbeamLightsIconSport.scaled(ui->lowbeamLightsIndicator->width(), ui->lowbeamLightsIndicator->height(), Qt::KeepAspectRatio));
    ui->lowbeamLightsIndicator->setVisible(false);
    QPixmap highbeamLightsIconSport(":/sport/sport/HighbeamLightsIconSport.png");
    ui->highbeamLightsIndicator->setPixmap(highbeamLightsIconSport.scaled(ui->highbeamLightsIndicator->width(), ui->highbeamLightsIndicator->height(), Qt::KeepAspectRatio));
    ui->highbeamLightsIndicator->setVisible(false);
    QPixmap positionLightsIconSport(":/sport/sport/PositionLightsIconSport.png");
    ui->positionLightsIndicator->setPixmap(positionLightsIconSport.scaled(ui->positionLightsIndicator->width(), ui->positionLightsIndicator->height(), Qt::KeepAspectRatio));
    ui->positionLightsIndicator->setVisible(false);

    actual_speed = 0;
    actual_power = 0;
    actual_battery_level = 0;
    actual_battery_temperature = 0;
    actual_engine_temperature = 0;
    //// testing
    //this->init();
    //// testing
}

SportMode::~SportMode()
{
    delete ui;
}

void SportMode::set_speed(int speed){
    if (speed > this->max_speed) {
        ui->speedIndicator->setText(QString::number(this->max_speed));
        this->actual_speed = speed;
    } else {
        ui->speedIndicator->setText(QString::number(speed));
        this->actual_speed = speed;
    }
}

void SportMode::set_power(int power){
    if ((qreal)power > this->max_power){
        ui->powerProgressBar->update_value(1);
        ui->powerIndicator->setText(QString::number(this->max_power));
    }
    else{
        qreal percent_value = power / this->max_power;
        ui->powerProgressBar->update_value(percent_value);
        ui->powerIndicator->setText(QString::number(power));
        ui->powerIndicator->update();
    }
    this->actual_power = power;
}

void SportMode::set_battery_level(int battery_level){
    if (battery_level > this->max_battery_level){
        ui->batteryIndicator->setText(QString::number(this->max_battery_level));
    } else {
        ui->batteryIndicator->setText(QString::number(battery_level));
    }
    this->actual_battery_level = battery_level;
    if (battery_level <= this->battery_level_low){
        QPixmap batteryIconSport(":/sport/sport/BatteryLevelIconRedSport.png");
        ui->batteryIcon->setPixmap(batteryIconSport.scaled(ui->batteryIcon->width(), ui->batteryIcon->height(), Qt::KeepAspectRatio));
    }
    else if(battery_level > this->battery_level_high){
        QPixmap batteryIconSport(":/sport/sport/BatteryLevelIconGreenSport.png");
        ui->batteryIcon->setPixmap(batteryIconSport.scaled(ui->batteryIcon->width(), ui->batteryIcon->height(), Qt::KeepAspectRatio));
    }
    else{
        QPixmap batteryIconSport(":/sport/sport/BatteryLevelIconYellowSport.png");
        ui->batteryIcon->setPixmap(batteryIconSport.scaled(ui->batteryIcon->width(), ui->batteryIcon->height(), Qt::KeepAspectRatio));
    }
}

void SportMode::set_battery_temperature(int battery_temperature){
    ui->batteryTemperatureIndicator->setText(QString::number(battery_temperature));
    this->actual_battery_temperature = battery_temperature;
    if (battery_temperature < this->battery_temperature_low){
        QPixmap batteryTemperatureIconSport(":/sport/sport/BatteryTemperatureIconGreenSport.png");
        ui->batteryTemperatureIcon->setPixmap(batteryTemperatureIconSport.scaled(ui->batteryTemperatureIcon->width(), ui->batteryTemperatureIcon->height(), Qt::KeepAspectRatio));
    }
    else if(battery_temperature >= this->battery_temperature_high){
        QPixmap batteryTemperatureIconSport(":/sport/sport/BatteryTemperatureIconRedSport.png");
        ui->batteryTemperatureIcon->setPixmap(batteryTemperatureIconSport.scaled(ui->batteryTemperatureIcon->width(), ui->batteryTemperatureIcon->height(), Qt::KeepAspectRatio));
    }
    else{
        QPixmap batteryTemperatureIconSport(":/sport/sport/BatteryTemperatureIconYellowSport.png");
        ui->batteryTemperatureIcon->setPixmap(batteryTemperatureIconSport.scaled(ui->batteryTemperatureIcon->width(), ui->batteryTemperatureIcon->height(), Qt::KeepAspectRatio));
    }
}

void SportMode::set_engine_temperature(int engine_temperature){
    ui->engineTemperatureIndicator->setText(QString::number(engine_temperature));
    this->actual_engine_temperature = engine_temperature;
    if (engine_temperature < this->engine_temperature_low){
        QPixmap engineTemperatureIconSport(":/sport/sport/EngineTemperatureIconGreenSport.png");
        ui->engineTemperatureIcon->setPixmap(engineTemperatureIconSport.scaled(ui->engineTemperatureIcon->width(), ui->engineTemperatureIcon->height(), Qt::KeepAspectRatio));
    }
    else if(engine_temperature >= this->engine_temperature_high){
        QPixmap engineTemperatureIconSport(":/sport/sport/EngineTemperatureIconRedSport.png");
        ui->engineTemperatureIcon->setPixmap(engineTemperatureIconSport.scaled(ui->engineTemperatureIcon->width(), ui->engineTemperatureIcon->height(), Qt::KeepAspectRatio));
    }
    else{
        QPixmap engineTemperatureIconSport(":/sport/sport/EngineTemperatureIconYellowSport.png");
        ui->engineTemperatureIcon->setPixmap(engineTemperatureIconSport.scaled(ui->engineTemperatureIcon->width(), ui->engineTemperatureIcon->height(), Qt::KeepAspectRatio));
    }
}

void SportMode::set_caution(){
    ui->cautionIndicator->setVisible(true);
}

void SportMode::reset_caution(){
    ui->cautionIndicator->setVisible(false);
}

void SportMode::set_left_direction_light(){
    ui->leftDirection->setVisible(true);
}

void SportMode::reset_left_direction_light(){
    ui->leftDirection->setVisible(false);
}

void SportMode::set_right_direction_light(){
    ui->rightDirection->setVisible(true);
}

void SportMode::reset_right_direction_light(){
    ui->rightDirection->setVisible(false);
}

void SportMode::set_highbeam_lights(){
    ui->highbeamLightsIndicator->setVisible(true);
}

void SportMode::reset_highbeam_lights(){
    ui->highbeamLightsIndicator->setVisible(false);
}

void SportMode::set_lowbeam_lights(){
    ui->lowbeamLightsIndicator->setVisible(true);
}

void SportMode::reset_lowbeam_lights(){
    ui->lowbeamLightsIndicator->setVisible(false);
}

void SportMode::set_position_lights(){
    ui->positionLightsIndicator->setVisible(true);
}

void SportMode::reset_position_lights(){
    ui->positionLightsIndicator->setVisible(false);
}

void SportMode::test(){
    this->set_speed(this->actual_speed + 1);
    this->set_battery_level(this->actual_battery_level + 1);
    this->set_power(this->actual_power + 1);
    this->set_engine_temperature(this->actual_engine_temperature + 1);
    this->set_battery_temperature(this->actual_battery_temperature + 1);
}
