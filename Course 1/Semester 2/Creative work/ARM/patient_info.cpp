#include "patient_info.h"
#include "ui_patient_info.h"
#include "mainwindow.h"

#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>

MainWindow* main;

patient_info::patient_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patient_info)
{
    ui->setupUi(this);

    QSettings settings("MyApp", "PatientInfo");
    QString fileName = settings.value("photoFile_" + ui->label_snils->text()).toString();

    if (QFile::exists(fileName)) {
        QPixmap photo(fileName);
        ui->label_photo->setPixmap(photo.scaled(ui->label_photo->size()));
    }
}

patient_info::~patient_info() {
    delete ui;
    saveLists();
    QSettings settings("MyApp", "PatientInfo");
    settings.setValue("photoFile_" + ui->label_snils->text(), photoFile);
}

void patient_info::setPatient(Patient* patient) {
    if (patient != nullptr) {
        ui->label_birth->setText(patient->getBirthDate().toString("dd.MM.yyyy"));
        ui->label_name->setText(patient->getName());
        ui->label_gender->setText(patient->getGender());
        ui->label_registration->setText(patient->getRegistration());
        ui->label_current_adress->setText(patient->getResidence());
        ui->label_work->setText(patient->getWork());
        ui->label_snils->setText(patient->getSnils());

        QString fileName = ui->label_snils->text() + ".txt";
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);

            while (!in.atEnd()) {
                QString line = in.readLine();

                QStringList fields = line.split(";");

                if (fields.size() == 4) {
                    QString date = fields[0];
                    QString diagnosis = fields[1];
                    QString treatment = fields[2];
                    QString recommendations = fields[3];

                    QList<QString> exam;
                    exam.append(date);
                    exam.append(diagnosis);
                    exam.append(treatment);
                    exam.append(recommendations);

                    exams.append(exam);
                }
            }
            file.close();
            updateTable();

            QString fileName = ui->label_snils->text() + "_photo.jpg";
            if (QFile::exists(fileName)) {
                QPixmap photo(fileName);
                ui->label_photo->setPixmap(photo.scaled(ui->label_photo->size()));
            }

            QString snils = ui->label_snils->text();
            fileName = snils + "_lists.txt";
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);

                int weightCount = (in.readLine()).toInt();
                for (int i = 0; i < weightCount; i++) {
                    QString text = in.readLine();
                    QListWidgetItem* item = new QListWidgetItem(text);
                    ui->listWidget_weight->addItem(item);
                }

                int heightCount = (in.readLine()).toInt();
                for (int i = 0; i < heightCount; i++) {
                    QString text = in.readLine();
                    QListWidgetItem* item = new QListWidgetItem(text);
                    ui->listWidget_height->addItem(item);
                }

                file.close();
            }
        }
    } else {
        QMessageBox::critical(this, "Ошибка", "Нет ссылки на пациента");
        return;
    }
}

void patient_info::on_home_button_clicked() {
    saveLists();
    this->close();
    main = new MainWindow(this);
    main->show();
}

void patient_info::on_saveButton_clicked() {
    QString fileName = ui->label_snils->text() + ".txt";

    QFile file(fileName);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);

        out << ui->dateEdit_exam->date().toString("dd.MM.yyyy") << ";";
        out << ui->lineEdit_diagnosis->text() << ";";
        out << ui->plainTextEdit_treatment->toPlainText() << ";";
        out << ui->comboBox_recommendations->currentText() << "\n";

        file.close();

        QList<QString> exam;
        exam.append(ui->dateEdit_exam->date().toString("dd.MM.yyyy"));
        exam.append(ui->lineEdit_diagnosis->text());
        exam.append(ui->plainTextEdit_treatment->toPlainText());
        exam.append(ui->comboBox_recommendations->currentText());

        exams.append(exam);

        updateTable();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл " + fileName + " для записи");
    }
}

void patient_info::updateTable() {
    ui->tableWidget_exams->clearContents();
    ui->tableWidget_exams->setRowCount(0);

    for (int i = 0; i < exams.size(); i++) {
        QList<QString> exam = exams[i];

        if (exam.size() == 4) {
            QString date = exam[0];
            QString diagnosis = exam[1];
            QString treatment = exam[2];
            QString recommendations = exam[3];

            ui->tableWidget_exams->insertRow(i);

            QTableWidgetItem* itemDate = new QTableWidgetItem(date);
            itemDate->setFlags(itemDate->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget_exams->setItem(i, 0, itemDate);

            QTableWidgetItem* itemDiagnosis = new QTableWidgetItem(diagnosis);
            itemDiagnosis->setFlags(itemDiagnosis->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget_exams->setItem(i, 1, itemDiagnosis);

            QTableWidgetItem* itemTreatment = new QTableWidgetItem(treatment);
            itemTreatment->setFlags(itemTreatment->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget_exams->setItem(i, 2, itemTreatment);

            QTableWidgetItem* itemRecommendations = new QTableWidgetItem(recommendations);
            itemRecommendations->setFlags(itemRecommendations->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget_exams->setItem(i, 3, itemRecommendations);
        }
    }
}

void patient_info::on_deleteButton_clicked() {
    int row = ui->tableWidget_exams->currentRow();
    if (row >= 0 && row < exams.size()) {
        exams.removeAt(row);
        ui->tableWidget_exams->removeRow(row);
        QMessageBox::information(this, "Удаление осмотра", "Осмотр успешно удален.");
    }
}

void patient_info::on_editButton_clicked() {
    int row = ui->tableWidget_exams->currentRow();
    if (row >= 0 && row < exams.size()) {
        QList<QString> exam = exams[row];

        if (exam.size() == 4) {
            QString date = exam[0];
            QString diagnosis = exam[1];
            QString treatment = exam[2];
            QString recommendations = exam[3];

            bool ok;
            date = QInputDialog::getText(this, "Редактирование осмотра", "Дата:", QLineEdit::Normal, date, &ok);
            if (!ok)
                return;
            diagnosis = QInputDialog::getText(this, "Редактирование осмотра", "Диагноз:", QLineEdit::Normal, diagnosis, &ok);
            if (!ok)
                return;
            treatment = QInputDialog::getText(this, "Редактирование осмотра", "Лечение:", QLineEdit::Normal, treatment, &ok);
            if (!ok)
                return;
            recommendations = QInputDialog::getText(this, "Редактирование осмотра", "Рекомендации:", QLineEdit::Normal, recommendations, &ok);
            if (!ok)
                return;

            exam[0] = date;
            exam[1] = diagnosis;
            exam[2] = treatment;
            exam[3] = recommendations;
            exams[row] = exam;

            updateTable();

            QMessageBox::information(this, "Редактирование осмотра", "Осмотр успешно отредактирован.");
        }
    }
}

void patient_info::on_changePhoto_button_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Выберите фото"), "", tr("Изображения (*.png *.jpg *.bmp);;Все файлы (*)"));

    if (!fileName.isEmpty()) {
        QPixmap photo(fileName);
        ui->label_photo->setPixmap(photo.scaled(ui->label_photo->size()));
        QImage image(fileName);
        QString snils = ui->label_snils->text();
        QString photoFile = snils + "_photo.jpg";
        image.save(photoFile);
    }
}

void patient_info::on_button_add_weight_clicked() {
    QString date = QInputDialog::getText(this, tr("Введите дату измерения"), tr("Дата (дд.мм.гггг.):"));
    if (!date.isEmpty()) {
        double weight = QInputDialog::getDouble(this, tr("Введите значение массы тела"), tr("Масса (кг):"), 0, 0, 999);
        if (weight > 0) {
            QListWidgetItem* item = new QListWidgetItem(date + " - " + QString::number(weight) + " кг");
            ui->listWidget_weight->addItem(item);
            saveLists();
        }
    }
}
void patient_info::on_button_delete_weight_clicked() {
    QListWidgetItem* item = ui->listWidget_weight->currentItem();
    if (item) {
        delete item;
        saveLists();
    }
}


void patient_info::on_button_add_height_clicked() {
    QString date = QInputDialog::getText(this, tr("Введите дату измерения"), tr("Дата (дд.мм.гггг):"));
    if (!date.isEmpty()) {
        double height = QInputDialog::getDouble(this, tr("Введите значение роста пацента"), tr("Рост (см):"), 0, 0, 999);
        if (height > 0) {
            QListWidgetItem* item = new QListWidgetItem(date + " - " + QString::number(height) + " см");
            ui->listWidget_height->addItem(item);
        }
    }
}
void patient_info::on_button_delete_height_clicked() {
    QListWidgetItem* item = ui->listWidget_height->currentItem();
    if (item) {
        delete item;
    }
}

void patient_info::saveLists() {
    QString snils = ui->label_snils->text();

    QString fileName = snils + "_lists.txt";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        int weightCount = ui->listWidget_weight->count();
        out << weightCount << "\n";
        for (int i = 0; i < weightCount; i++) {
            QString text = ui->listWidget_weight->item(i)->text();
            out << text << "\n";
        }

        int heightCount = ui->listWidget_height->count();
        out << heightCount << "\n";
        for (int i = 0; i < heightCount; i++) {
            QString text = ui->listWidget_height->item(i)->text();
            out << text << "\n";
        }

        file.close();
    }
}

void patient_info::on_button_add_recommendation_clicked() {
    QString text = QInputDialog::getText(this, tr("Введите текст рекомендации"), tr("Рекомендация:"));
    if (!text.isEmpty()) {
        ui->comboBox_recommendations->addItem(text);
    }
}

