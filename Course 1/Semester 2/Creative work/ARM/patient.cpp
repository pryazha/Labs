#include "patient.h"

Patient::Patient(QDate birthDate, QString gender, QString name, QString registration, QString residence, QString work, QString snils) {
    this->birthDate = birthDate;
    this->gender = gender;
    this->name = name;
    this->registration_adress = registration;
    this->current_adress = residence;
    this->work = work;
    this->snils = snils;
}

QDate Patient::getBirthDate() const {
    return birthDate;
}
void Patient::setBirthDate(const QDate &birthDate) {
    this->birthDate = birthDate;
}

QString Patient::getGender() const {
    return gender;
}
void Patient::setGender(const QString &gender) {
    this->gender = gender;
}

QString Patient::getName() const {
    return name;
}
void Patient::setName(const QString &name) {
    this->name = name;
}

QString Patient::getRegistration() const {
    return registration_adress;
}
void Patient::setRegistration(const QString &registration_adress) {
    this->registration_adress = registration_adress;
}

QString Patient::getResidence() const {
    return current_adress;
}
void Patient::setResidence(const QString &current_adress) {
    this->current_adress = current_adress;
}

QString Patient::getWork() const {
    return work;
}
void Patient::setWork(const QString &work) {
    this->work = work;
}

QString Patient::getSnils() const {
    return snils;
}
void Patient::setSnils(const QString &snils) {
    this->snils = snils;
}
