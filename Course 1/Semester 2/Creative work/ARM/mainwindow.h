#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "patient_info.h"
#include "patient.h"

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_add_patient_clicked();
    void on_delete_patient_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    patient_info* patient_window;
    QList<Patient*> patients;
    QString fileName;
};
#endif // MAINWINDOW_H
