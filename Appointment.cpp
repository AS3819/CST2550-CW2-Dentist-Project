#include "Appointment.h"

//Setter methods.

void Appointment::setID(int ID) {
  appointmentID = ID;
}

void Appointment::setRoom(Room* newRoom) {
  room = newRoom;
}

void Appointment::setDate(unsigned long int newDate) {
  date = newDate;
}

void Appointment::setDentist(Dentist* newDentist) {
  dentist = newDentist;
}

void Appointment::setPatient(Patient* newPatient) {
    if (isFree) {
        patient = newPatient;
        isFree = false;
    }
}

//Getter methods.

int Appointment::getID() const {
  return appointmentID;
}

Room* Appointment::getRoom() const {
  return room;
}

unsigned long int Appointment::getDate() const {
  return date;
}

Dentist* Appointment::getDentist() const {
  return dentist;
}

Patient* Appointment::getPatient() const {
  return patient;
}

bool Appointment::getIsFree() const {
  return isFree;
}
