// patient.h
#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDate>

class Patient
{
public:
    Patient(QDate birhtDate, QString gender, QString name, QString registration, QString residence, QString work, QString snils);

    QDate getBirthDate() const;
    void setBirthDate(const QDate &birthDate);

    QString getGender() const;
    void setGender(const QString &gender);

    QString getName() const;
    void setName(const QString &name);

    QString getRegistration() const;
    void setRegistration(const QString &registration_adress);

    QString getResidence() const;
    void setResidence(const QString &current_adress);

    QString getWork() const;
    void setWork(const QString &work);

    QString getSnils() const;
    void setSnils(const QString &snils);

private:
    QDate birthDate;
    QString gender;
    QString name;
    QString registration_adress;
    QString current_adress;
    QString work;
    QString snils;
};

#endif // PATIENT_H
