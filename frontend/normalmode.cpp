#include "normalmode.h"
#include "ui_normalmode.h"

NormalMode::NormalMode(): ui(new Ui::NormalMode)
{
    ui->setupUi(this);
    // Constant initialization
    QPixmap batteryIconNormal(":/normal/normal/BatteryIconNormal.png");
    ui->batteryIcon->setPixmap(batteryIconNormal.scaled(ui->batteryIcon->width(), ui->batteryIcon->height(), Qt::KeepAspectRatio));
    //ui->batteryIcon->setGeometry(QRect(715, 195, 50, 50));
    QPixmap powerIconNormal(":/normal/normal/PowerIconNormal.png");
    ui->powerIcon->setPixmap(powerIconNormal.scaled(ui->powerIcon->width(), ui->powerIcon->height(), Qt::KeepAspectRatio));
    //ui->powerIcon->setGeometry(QRect(235, 195, 50, 50));
    QPixmap batteryTemperatureIconNormal(":/normal/normal/BatteryTemperatureIconNormal.png");
    ui->batteryTemperatureIcon->setPixmap(batteryTemperatureIconNormal.scaled(ui->batteryTemperatureIcon->width(), ui->batteryTemperatureIcon->height(), Qt::KeepAspectRatio));
    QPixmap engineTemperatureIconNormal(":/normal/normal/EngineTemperatureIconNormal.png");
    ui->engineTemperatureIcon->setPixmap(engineTemperatureIconNormal.scaled(ui->engineTemperatureIcon->width(), ui->engineTemperatureIcon->height(), Qt::KeepAspectRatio));

    // Initial values
    QPixmap cautionIconNormal(":/normal/normal/CautionIconNormal.png");
    ui->cautionIndicator->setPixmap(cautionIconNormal.scaled(ui->cautionIndicator->width(), ui->cautionIndicator->height(), Qt::KeepAspectRatio));
    ui->cautionIndicator->setVisible(false);
    QPixmap rightDirectionIconNormal(":/normal/normal/RightDirectionIconNormal.png");
    ui->rightDirection->setPixmap(rightDirectionIconNormal.scaled(ui->rightDirection->width(), ui->rightDirection->height(), Qt::KeepAspectRatio));
    ui->rightDirection->setVisible(false);
    QPixmap leftDirectionIconNormal(":/normal/normal/LeftDirectionIconNormal.png");
    ui->leftDirection->setPixmap(leftDirectionIconNormal.scaled(ui->leftDirection->width(), ui->leftDirection->height(), Qt::KeepAspectRatio));
    ui->leftDirection->setVisible(false);
    QPixmap lowbeamLightsIconNormal(":/normal/normal/LowbeamLightsIconNormal.png");
    ui->lowbeamLightsIndicator->setPixmap(lowbeamLightsIconNormal.scaled(ui->lowbeamLightsIndicator->width(), ui->lowbeamLightsIndicator->height(), Qt::KeepAspectRatio));
    ui->lowbeamLightsIndicator->setVisible(false);
    QPixmap highbeamLightsIconNormal(":/normal/normal/HighbeamLightsIconNormal.png");
    ui->highbeamLightsIndicator->setPixmap(highbeamLightsIconNormal.scaled(ui->highbeamLightsIndicator->width(), ui->highbeamLightsIndicator->height(), Qt::KeepAspectRatio));
    ui->highbeamLightsIndicator->setVisible(false);
    QPixmap positionLightsIconNormal(":/normal/normal/PositionLightsIconNormal.png");
    ui->positionLightsIndicator->setPixmap(positionLightsIconNormal.scaled(ui->positionLightsIndicator->width(), ui->positionLightsIndicator->height(), Qt::KeepAspectRatio));
    ui->positionLightsIndicator->setVisible(false);

    actual_speed = 0;
    actual_power = 0;
    actual_battery_level = 0;
    actual_battery_temperature = 0;
    actual_engine_temperature = 0;

    ////// testing
    //this->init();
    ////// testing
}

NormalMode::~NormalMode()
{
    delete ui;
}

void NormalMode::set_speed(int speed){
    if ((qreal)speed > this->max_speed){
        ui->speedProgressBar->update_value(1);
        ui->speedIndicator->setText(QString::number(this->max_speed));
    }
    else{
        qreal percent_value = speed / this->max_speed;
        ui->speedProgressBar->update_value(percent_value);
        ui->speedIndicator->setText(QString::number(speed));
    }
    this->actual_speed = speed;
}

void NormalMode::set_power(int power){
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

void NormalMode::set_battery_level(int battery_level){
    if ((qreal)battery_level > this->max_battery_level){
        ui->batteryProgressBar->update_value(1);
        ui->batteryIndicator->setText(QString::number(this->max_battery_level));
    }
    else{
        qreal percent_value = battery_level / this->max_battery_level;
        ui->batteryProgressBar->update_value(percent_value);
        ui->batteryIndicator->setText(QString::number(battery_level));
    }
    this->actual_battery_level = battery_level;
}

void NormalMode::set_battery_temperature(int battery_temperature){
    ui->batteryTemperatureIndicator->setText(QString::number(battery_temperature));
    this->actual_battery_temperature = battery_temperature;
}

void NormalMode::set_engine_temperature(int engine_temperature){
    ui->engineTemperatureIndicator->setText(QString::number(engine_temperature));
    this->actual_engine_temperature = engine_temperature;
}

void NormalMode::set_caution(){
    this->caution_status = true;
    ui->cautionIndicator->setVisible(true);
}

void NormalMode::reset_caution(){
    this->caution_status = false;
    ui->cautionIndicator->setVisible(false);
}

void NormalMode::set_left_direction_light(){
    this->left_direction_light_status = true;
    ui->leftDirection->setVisible(true);
}

void NormalMode::reset_left_direction_light(){
    this->left_direction_light_status = false;
    ui->leftDirection->setVisible(false);
}

void NormalMode::set_right_direction_light(){
    this->right_direction_light_status = true;
    ui->rightDirection->setVisible(true);
}

void NormalMode::reset_right_direction_light(){
    this->right_direction_light_status = false;
    ui->rightDirection->setVisible(false);
}

void NormalMode::set_highbeam_lights(){
    this->highbeam_lights_status = true;
    ui->highbeamLightsIndicator->setVisible(true);
}

void NormalMode::reset_highbeam_lights(){
    this->highbeam_lights_status = false;
    ui->highbeamLightsIndicator->setVisible(false);
}

void NormalMode::set_lowbeam_lights(){
    this->lowbeam_lights_status = true;
    ui->lowbeamLightsIndicator->setVisible(true);
}

void NormalMode::reset_lowbeam_lights(){
    this->lowbeam_lights_status = false;
    ui->lowbeamLightsIndicator->setVisible(false);
}

void NormalMode::set_position_lights(){
    this->position_lights_status = true;
    ui->positionLightsIndicator->setVisible(true);
}

void NormalMode::reset_position_lights(){
    this->position_lights_status = false;
    ui->positionLightsIndicator->setVisible(false);
}

void NormalMode::test(){
    if (this->simulation_stage == 0) {
        this->second_time_period--;
        if (this->second_time_period <= 0) {
            this->set_lowbeam_lights();
            this->set_position_lights();
            this->simulation_stage = 1;
            this->second_time_period = 20;
        }
    } else if (this->simulation_stage == 1) {
        this->second_time_period--;
        if (this->second_time_period <= 0) {
            this->simulation_stage = 2;
            this->second_time_period = 120;
        }
    } else if (this->simulation_stage == 2) {
        this->second_time_period--;
        if (this->actual_power < 32) {
            this->set_power(this->actual_power + 2);
        }
        this->set_speed(this->actual_speed + 1);
        if (this->second_time_period <= 0) {
            this->simulation_stage = 3;
            this->second_time_period = 40;
        }
    } else if (this->simulation_stage == 3) {
        this->second_time_period--;
        if (this->actual_power > 20) {
            this->set_power(this->actual_power - 1);
        }
    }
}
