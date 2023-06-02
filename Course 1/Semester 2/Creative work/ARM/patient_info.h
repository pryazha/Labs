#ifndef PATIENT_INFO_H
#define PATIENT_INFO_H

#include "patient.h"

#include <QDialog>

namespace Ui {
class patient_info;
}

class patient_info : public QDialog
{
    Q_OBJECT

public:
    explicit patient_info(QWidget *parent = nullptr);
    ~patient_info();

    void setPatient(Patient* patient);

private slots:
    void on_home_button_clicked();

private:
    Ui::patient_info *ui;
};

#endif // PATIENT_INFO_H
