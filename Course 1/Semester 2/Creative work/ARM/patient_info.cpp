#include "patient_info.h"
#include "ui_patient_info.h"
#include "mainwindow.h"

#include <QMessageBox>

MainWindow* main;

patient_info::patient_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patient_info)
{
    ui->setupUi(this);
}

patient_info::~patient_info() {
    delete ui;
}

void patient_info::setPatient(Patient* patient) {
    if (patient != nullptr) {
        ui->label_gender->setText(patient->getName());
        ui->label_registration->setText(patient->getRegistration());
        ui->label_current_adress->setText(patient->getResidence());
        ui->label_work->setText(patient->getWork());
        ui->label_snils->setText(patient->getSnils());
    } else {
        QMessageBox::critical(this, "Ошибка", "Нет ссылки на пациента");
        return;
    }
}

void patient_info::on_home_button_clicked() {
    hide();
    main = new MainWindow(this);
    main->show();
}
