#ifndef PATIENT_INFO_H
#define PATIENT_INFO_H

#include "patient.h"

#include <QDialog>
#include <QSettings>
#include <QFile>
#include <QTextStream>
#include <QCloseEvent>

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
    void saveLists();
    void saveExams();

private slots:
    void on_home_button_clicked();
    void on_saveButton_clicked();
    void on_deleteButton_clicked();
    void on_editButton_clicked();


    void on_changePhoto_button_clicked();

    void on_button_add_weight_clicked();

    void on_button_delete_weight_clicked();

    void on_button_add_height_clicked();

    void on_button_delete_height_clicked();

    void on_button_add_recommendation_clicked();

private:
    Ui::patient_info *ui;
    QList<QList<QString>> exams;
    void updateTable();
    QString photoFile;
};

#endif // PATIENT_INFO_H
