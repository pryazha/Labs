#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileName = "patients.txt";

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();

            QStringList fields = line.split(";");

            if (fields.size() == 7) {
                QDate birthDate = QDate::fromString(fields[0], "dd.MM.yyyy");
                QString gender = fields[1];
                QString name = fields[2];
                QString registration = fields[3];
                QString residence = fields[4];
                QString work = fields[5];
                QString snils = fields[6];

                Patient* patient = new Patient(birthDate, gender, name, registration, residence, work, snils);
                patients.append(patient);

                QListWidgetItem* item = new QListWidgetItem(name);
                ui->listWidget->addItem(item);
            }
        }
        file.close();
    }
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    int index = ui->listWidget->currentRow();

    if (index >= 0 && index < patients.size()) {
        Patient* patient = patients.takeAt(index);
        if (patient != nullptr) {
            hide();
            patient_window = new patient_info(this);
            patient_window->setPatient(patient);
            patient_window->show();
        }
    }
}


void MainWindow::on_add_patient_clicked() {
    QString name = QInputDialog::getText(this, "Введите ФИО пациента", "ФИО:");

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите имя пациента");
        return;
    }

    QString gender = QInputDialog::getText(this, "Введите пол пациента", "Пол:");
    QDate birthDate = QDate::fromString(QInputDialog::getText(this, "Введите дату рождения пациента (dd.mm.yyyy)", "Дата рождения:"), "dd.MM.yyyy");
    QString registration = QInputDialog::getText(this, "Введите место регистрации пациента", "Регистрация:");
    QString residence = QInputDialog::getText(this, "Введите место проживания пациента", "Проживание:");
    QString work = QInputDialog::getText(this, "Введите работу пациента", "Работа:");
    QString snils = QInputDialog::getText(this, "Введите СНИЛС пациента", "СНИЛС:");

    if (snils.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите СНИЛС пациента");
        return;
    }

    if (ui->listWidget->findItems(snils, Qt::MatchExactly).size() > 0) {
        QMessageBox::warning(this, "Ошибка", "Пациент с таким СНИЛС уже существует");
        return;
    }

    Patient* patient = new Patient(birthDate, gender, name, registration, residence, work, snils);
    patients.append(patient);

    QListWidgetItem* item = new QListWidgetItem(name);
    ui->listWidget->addItem(item);

    QFile file(fileName);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << birthDate.toString("dd.MM.yyyy") << ";" << gender << ";" << name << ";" << registration << ";" << residence << ";" << work << ";" << snils << "\n";
        file.close();
    }
}


void MainWindow::on_delete_patient_clicked() {
    int index = ui->listWidget->currentRow();

    if (index >= 0 && index < patients.size()) {
        delete ui->listWidget->takeItem(index);
        delete patients.takeAt(index);
        QMessageBox::information(this, "Удаление пациента", "Пациент успешно удален.");
    }

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (Patient* patient : patients) {
            out << patient->getBirthDate().toString("dd.MM.yyyy") << ";" << patient->getGender() << ";" << patient->getName() << ";" << patient->getRegistration() << ";" << patient->getResidence() << ";" << patient->getWork() << ";" << patient->getSnils() << "\n";
        }
        file.close();
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
    Patient* patient = dynamic_cast<Patient*>(item);
    if (patient != nullptr) {
        hide();
        patient_window = new patient_info(this);
        patient_window->setPatient(patient);
        patient_window->show();
    }
}
