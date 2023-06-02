#include "patient.h"

Patient::Patient(QString gender, QString name, double height, double weight, QString registration, QString residence, QString work, QString snils) {
    this->gender = gender;
    this->name = name;
    this->height = height;
    this->weight = weight;
    this->registration_adress = registration;
    this->current_adress = residence;
    this->work = work;
    this->snils = snils;
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

double Patient::getHeight() const {
    return height;
}
void Patient::setHeight(double height) {
    this->height = height;
}

double Patient::getWeight() const {
    return weight;
}
void Patient::setWeight(double weight) {
    this->weight = weight;
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
