// patient.h
#ifndef PATIENT_H
#define PATIENT_H

#include <QString>

class Patient
{
public:
    Patient(QString gender, QString name, double height, double weight, QString registration, QString residence, QString work, QString snils);

    QString getGender() const;
    void setGender(const QString &gender);

    QString getName() const;
    void setName(const QString &name);

    double getHeight() const;
    void setHeight(double height);

    double getWeight() const;
    void setWeight(double weight);

    QString getRegistration() const;
    void setRegistration(const QString &registration_adress);

    QString getResidence() const;
    void setResidence(const QString &current_adress);

    QString getWork() const;
    void setWork(const QString &work);

    QString getSnils() const;
    void setSnils(const QString &snils);

private:
    QString gender;
    QString name;
    double height;
    double weight;
    QString registration_adress;
    QString current_adress;
    QString work;
    QString snils;
};

#endif // PATIENT_H
